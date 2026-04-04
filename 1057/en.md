### **Tutorial: LightOJ 1057**

**Prerequisites:** Bitmask DP, Traveling Salesperson Problem (TSP), Chebyshev Distance

#### **Observation 1: Calculating Distance**
We are given a grid where we can move in all 8 directions (horizontally, vertically, and diagonally). This implies that the shortest distance between any two cells $(r_1, c_1)$ and $(r_2, c_2)$ is calculated using the **Chebyshev distance**: 
$$\text{dist}((r_1, c_1), (r_2, c_2)) = \max(|r_1 - r_2|, |c_1 - c_2|)$$

*Proof:* To minimize moves, we should move diagonally as much as possible because one diagonal move changes both our X and Y coordinates simultaneously. We do this until we align with our target on either the X or Y axis, after which we move in a straight line. The total number of moves will always be bounded by the maximum of the absolute differences of their coordinates.

#### **Observation 2: Reducing the Problem (TSP)**
Let $K$ be the total number of gold pieces ('g') on the grid. We can assign each gold piece a unique ID from 0 to $K-1$. The starting position 'x' is our base. 
The problem now reduces to a variation of the **Traveling Salesperson Problem (TSP)**: find the shortest path that starts at the base, visits all $K$ nodes, and returns to the base. 

Because $K \le 15$, we can solve this efficiently using Dynamic Programming with bitmasking.

---

### **DP Formulation**

**State Definition:**
Let `dp[mask][i]` be the minimum number of moves required to visit the subset of gold pieces represented by `mask`, ending at gold piece $i$. 
* `mask` is an integer where the $j$-th bit is 1 if the $j$-th gold piece has been visited, and 0 otherwise.
* $i$ is the index of the last visited gold piece.

**Base Cases:**
Initially, we only have one gold piece in our path. For every gold piece $i$ from 0 to $K-1$:
$dp[1 \ll i][i] = \text{dist}(\text{start}, \text{gold}_i)$

**Transitions:**
To compute `dp[mask][i]`, we must transition from a previous state where we had visited all nodes in the `mask` *except* node $i$, ending at some node $j$.
For every node $i$ present in the `mask`, we iterate over every other node $j$ present in the `mask` ($i \neq j$):
$$dp[\text{mask}][i] = \min_{j}(dp[\text{mask} - (1 \ll i)][j] + \text{dist}(\text{gold}_j, \text{gold}_i))$$

**Final Answer:**
Once the DP table is fully populated, the final answer requires us to return to the starting position 'x'. We take the minimum over all possible last-visited gold pieces:
$$\text{Ans} = \min_{i} (dp[(1 \ll K) - 1][i] + \text{dist}(\text{gold}_i, \text{start}))$$
*(Note: We must handle the edge case where K = 0 seperately. If there is no gold, the answer is just 0!)*

---

### **Complexity Analysis & Optimization**

A loose upper bound for the time complexity is $\mathcal{O}(K^2 2^K)$ per testcase. 

At first glance, this might look too slow. The maximum number of gold pieces is $K = 15$. If we blindly iterate through all $2^{15}$ masks, and for each mask run a $15 \times 15$ nested loop to find $i$ and $j$, the operations per test case would be $15^2 \times 2^{15} \approx 7.3 \times 10^6$. Across 100 test cases, this is roughly $7.4 \times 10^8$ operations, which is beyond the restricted time.

**The Optimization:**
We can drastically reduce the constant factor by **only iterating through the active bits** (nodes that are actually present in the current mask). 

The exact number of operations with this optimization: For any mask that has exactly $c$ bits turned on, we test $c$ options for the current node $i$, and $c-1$ options for the previous node $j$. The number of possible masks with exactly $c$ bits turned on is $\binom{K}{c}$. 

Summing this up for all possible subset sizes gives us our exact worst-case transitions:
$$\sum_{c=1}^{K} \binom{K}{c} c(c-1) = K(K-1)2^{K-2}$$

If we plug in $K = 15$:
$$15 \times 14 \times 2^{13} = 1,720,320 \text{ operations}$$

Across the maximum of 100 test cases, this tight bound results in roughly 172 million operations in total $\approx 1.72 \times 10^8$.

<details>
<summary><b>Solution code (C++)</b></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int get_dist(pair<int, int> a, pair<int, int> b) {
    return max(abs(a.first - b.first), abs(a.second - b.second));
}

void solve(int tc) {
    int r, c;
    cin >> r >> c;
    pair<int, int> start;
    vector<pair<int, int>> gold;
    for (int i = 0; i < r; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < c; ++j) {
            if (row[j] == 'x') {
                start = {i, j};
            } else if (row[j] == 'g') {
                gold.push_back({i, j});
            }
        }
    }
    int K = gold.size();
    if (K == 0) {
        cout << "Case " << tc << ": 0\n";
        return;
    }
    vector<vector<int>> dp(1 << K, vector<int>(K, INF));
    for (int i = 0; i < K; ++i) {
        dp[1 << i][i] = get_dist(start, gold[i]);
    }
    for (int mask = 1; mask < (1 << K); ++mask) {
        vector<int> active;
        for (int i = 0; i < K; ++i) {
            if ((mask >> i) & 1) {
                active.push_back(i);
            }
        }
        if (active.size() <= 1) continue;
        for (int i : active) {
            int prev_mask = mask ^ (1 << i);
            for (int j : active) {
                if (i == j) continue;
                int dist = get_dist(gold[j], gold[i]);
                dp[mask][i] = min(dp[mask][i], dp[prev_mask][j] + dist);
            }
        }
    }
    int ans = INF;
    int full_mask = (1 << K) - 1;
    for (int i = 0; i < K; ++i) {
        int return_dist = get_dist(gold[i], start);
        ans = min(ans, dp[full_mask][i] + return_dist);
    }
    cout << "Case " << tc << ": " << ans << "\n";
}

int main() {
    int t;
    if (cin >> t) {
        for (int i = 1; i <= t; ++i) {
            solve(i);
        }
    }
    return 0;
}
