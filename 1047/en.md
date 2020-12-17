# LightOJ 1047 - Neighbor House

### Short Description:
You are given `N` houses & the cost of coloring each of these houses in any one of three colors `R(red)`, `G(green)`, `B(blue)` respectively. But, you have to maintain the **condition** that, **neighboring houses can't have the same color**, where the neighbors of house `i` are houses `i-1` and `i+1` (if exists). **The first and last houses are not neighbors.**

The first line contains an integer `T` the number of test cases to follow. Each case begins with a blank line and an integer `N` denoting the number of houses. Each of the next `N` lines will contain 3 integers "R G B" (quotes for clarity only), where `R`, `G` and `B` are the **costs** of painting the corresponding house `red`, `green`, and `blue`, respectively. 
You need to find the **minimum cost** of coloring these houses.

--- 
### Solution Idea:

We'll use the **Dynamic Programming** bottom-up approach to solve this problem. Let's assume that we're processing the houses from left to right, coloring them maintaining the condition and keeping track of total costs. To color a particular house we just need to know the color of previous house. If the previous house is colored with `R` then, now we can use either `B` or `G`. If the previously used color is `B`, now we can use either `R` or `G`. Similarly, if the previously used color is `G`, now we can use either `R` or `B`. For the first house, we can use any of these three colors. So, we know how to pick the valid color, but how do we find the minimum costs of doing so?


Let's define the **state** of our DP solution:

For simplicity, let's assign some numerical values to each of the colors. `R = 1`, `G = 2`, `B = 3`

`cost[i][j] = cost of coloring i'th house with the color j`

`dp[i][j] = minimum total costs of coloring first i houses where the i'th house is colored with color j`

If we have no houses, then we don't need to color them, so:
`dp[0][1] = dp[0][2] = dp[0][3] = 0`

Let's say, we're currently on `i'th` house & we want to color it with color `1(R)`, we take the minimum of the total cost of coloring the first `(i-1)` houses using color `2(G)` or `3(B)` to color the `(i-1)th` house, which is: `min(dp[i - 1][2], dp[i - 1][3])` & add the `cost[i][1] = cost of coloring i'th` house to get the costs upto `i'th` position. 
Similarly, we can calculate the costs for using color `2(G)` and `3(B)` for the `i'th` position.

```C++
dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + cost[i][1]
dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + cost[i][2]
dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][3]
```
or,
```
i = the position of the houses we're currently considering
j = the color we want to use for this house
k = the colors which are not same as the current color j
```
```C++
for (int j = 1; j <= 3; j++) {
    for (int k = 1; k <= 3; k++) {
        if (j != k) {
            dp[i][j] = min(dp[i][j], cost[i][j] + dp[i - 1][k])
        }
    }
}
```
So, according to our initial `dp[][]` definition, our final answer would be: `min(dp[n][1], dp[n][2], dp[n][3])` the costs of coloring first `n` houses, where the `n'th` house is colors with color `1(R)`, `2(G)` or `3(B)`

---
1. It's also possible to solve this problem using top-down DP.
2. Initialize the dp[][] array  with some large possible value, helps in finding the minimum by comparing.
3. Format the output properly according to the output section.

---

See the code below if you still need some help with the implementation:

### C++

```C++
#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;
 
int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        int n;
        scanf("%d", &n);
        vector <vector <int> > cost (n + 5, vector <int> (5, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                scanf("%d",&cost[i][j]);
            }
        }
       
        vector <vector <int> > dp (n + 5, vector <int> (5, inf));
        for (int i = 1; i <= 3; i++) dp[0][i] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int k = 1; k <= 3; k++) {
                    if (j != k) {
                        dp[i][j] = min(dp[i][j], cost[i][j] + dp[i - 1][k]);
                    }
                }
            }
        }
       
        int ans = inf;
        for (int i = 1; i <= 3; i++) ans = min(ans, dp[n][i]);
        printf("Case %d: %d\n", tc, ans);
    }
    return 0;
}

```





