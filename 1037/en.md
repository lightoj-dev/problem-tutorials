# LOJ 1037 - Agent 47

## Summary
Given **n** targets and a **n x n** matrix per test case:

v[**i**] = number of shots to kill **i**'th target using **KM .45 Tactical (USP)** . 0 <= i < n
cost[**i**][**j**] = number of shots to kill **j**'th target using weapon provided from **i**'th arsenal after killing **i**'th target itself.

We have to compute the minimum number of shots to kill all targets using **KM .45 Tactical (USP)** and weapons from the arsenals of already killed targets.

## Prerequisite

Bitmask Dynamic Programming

Great source for learning bitmask DP for the first time: https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/tutorial/

## Solution
For each mask we brute force over all distinct pairs (**i**, **j**) **contained in the mask** where considering **i's** being the last to kill, we try weapons from **j's** arsenals to kill **it** and take the minimum result overall. This will ensure the optimum result for that particular mask. Doing that for all masks in increasing order, and our result will be the mask that contains every target.

## Complexity
- Time Complexity: `O(T * (2^n * n^2))`.
- Memory Complexity: `O(2^n)`.

## Code

### C++

```cpp
#include <bits/stdc++.h>

using namespace std;


int main() {

	// for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int INF = 1e9;

    int t;
    cin >> t;

    for(int ts = 1; ts <= t; ++ts) {
        int n;
        cin >> n;

        vector <int> v(n, 0);
        vector <vector <int>> cost(n+1, vector <int> (n, INF));
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
            cost[i][i] = 0;
        }

        for(int i = 0; i < n; ++i) {
            string str;
            cin >> str;
            for(int j = 0; j < n; ++j) {
                int w = str[j] - '0';
                cost[i][j] = min(cost[i][j], v[j]); // KM.45 Tactical (USP) is always available to use
                if (w != 0) cost[i][j] = min(cost[i][j], v[j] / w + (v[j] % w != 0? 1:0)); // updating with j'th weapon from i'th arsenal
            }
        }
        
        // dp[mask] = minimum cost of killing all targets in the 'mask'
        vector <int> dp(1<<n, INF);
        for(int i = 0; i < n; ++i) {
	        dp[1<<i]= v[i]; // base case
        }

        for(int mask = 0; mask < (1<<n); ++mask) {
            for(int i = 0; i < n; ++i) {
                if ((mask & (1<<i)) == 0) continue;
                for(int j = 0; j < n; ++j) {
                    if (i != j && (mask & (1<<j)) != 0) {
                    // considering i being the last target to kill; we try all weapons available to get the minimum cost
                        dp[mask] = min(dp[mask], dp[mask ^ (1<<i)] + cost[j][i]);
                    }
                }
            }
        }
        cout << "Case " << ts << ": " << dp[(1<<n)-1] << '\n';
    }
    
    return 0;
}