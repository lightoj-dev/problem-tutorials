# LOJ 1092 - Lighted Panels


## Prerequisite
[Bitmask DP](https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/tutorial/)

## Solution
`Observation 1`: 

`Observation 2`: If there is a sequence of moves that lead to an answer then it's also possible to do the moves in top-down manner, i.e, toggle the necessary cells from the topmost row to the bottommost row. Follows immediately from `observation 1` Hence, dynamic programming at rescue!

`Approach`: We iterate through each row, starting from the topmost. For each row, we explore every combination of toggle switching, determining which cells to toggle and which to leave unchanged. By selecting specific cells, we toggle all adjacent and diagonal cells that correspond to the immediate upper, lower, and current row cells.

Before moving on to the next row, we check if all cells in the previous row are lit. If any cells remain unlit, we discard the current combination as a potential path to a local optimum, and proceed to the next combination. This process continues until we reach the bottommost row, which represents a local optimum.

Among all the local optimums, we select the one with the minimum value as the answer to our problem.

## Complexity
- Time Complexity: **O(T * R * 2<sup>2C</sup>)**.
- Memory Complexity: **O(R * 2<sup>2C</sup>)**.


## Code

### C++

```cpp
#include <bits/stdc++.h>

using namespace std;


const int INF = 100;

const int MAX_ROW = 9;
const int MAX_COL = 9;

int mask[MAX_ROW], dp[MAX_ROW][1<<MAX_COL][1<<MAX_COL];

int r, c;

int DP(int row, int cur_mask, int prev_mask) {
    if (row == r) {
        return prev_mask == (1<<c)-1? 0 : INF;
    }

    // Taking reference for not writing dp[row][cur_mask][prev_mask] many times
    int &ret = dp[row][cur_mask][prev_mask];
    if (ret != -1) return ret;

    ret = INF;
    // For every row combination of toggled cells
    for(int i = 0; i < (1<<c); ++i) {
        int cnt = 0;
        int tmp[3] = {prev_mask, cur_mask, mask[row + 1]};

        for(int j = 0; j < c; ++j) {
            // If the j'th bit on, that means don't toggle
            if (i & (1<<j)) continue;

            // Otherwise toggle it and its surroundings
            cnt++;
            
            /*
               j-1 j j+1
                |_|_|_| previous
                |_|_|_| current
                |_|_|_| next
            */

            for(int k = 0; k < 3; ++k) {
                tmp[k] = tmp[k] ^ (1<<j);
            }

            if (j - 1 >= 0) {
                for(int k = 0; k < 3; ++k) {
                    tmp[k] = tmp[k] ^ (1<<(j-1));
                }
            }

            if (j + 1 < c) {
                for(int k = 0; k < 3; ++k) {
                    tmp[k] = tmp[k] ^ (1<<(j+1));
                }
            }
        }

        // All cells of the previous row have to lighted. Otherwise there will be no way around for them to be toggled later
        if (row == 0 || (tmp[0] == (1<<c)-1)) {
            ret = min(ret, cnt + DP(row + 1, tmp[2], tmp[1]));
        }
    }

    return ret;
}

int main() {
    
    // For fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int ts = 1; ts <= t; ++ts) {
        cin >> r >> c;

        memset(dp, -1, sizeof(dp));
        memset(mask, 0, sizeof(mask));

        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                char ch;
                cin >> ch;
                if (ch == '*') {
                    mask[i] |= 1<<j;
                }
            }
        }

        int ans = DP(0, mask[0], 0);

        cout << "Case " << ts << ": ";

        if (ans == INF) {
            cout << "impossible\n";
        }
        else {
            cout << ans << '\n';
        }

    }

    return 0;
}
```
