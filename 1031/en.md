# **LOJ 1031 - Easy Game**

## **Solution Idea**
You can solve the problem using Dynamic Programming concept.

- Create a prefix_sum array. 
- Think about the DP state. When you are in range i to j what could be the answer ? 
- you should store maximum difference in dp.
- When you want to compute ans for range i to j : 
    - There can be 3 possible ans:
        - You can take whole range i to j
        - You can take one or more numbers from the left-end
        - You can take one or more numbers from the right-end
    - So the idea will be as follow
        - `dp[i][j] = prefix_sum(taken_range) - dp of other range`
- for base case : Think about what will be the ans when n = 1 ? 
    

## **Solution Code(C++)**
```C++
#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<ll>> dp;
vector<ll> preSum;

ll get(int i, int j)
{
    return preSum[j + 1] - preSum[i];
}

void solve()
{
    int n;
    cin >> n;

    dp.assign(n + 1, vector<ll>(n + 1));
    preSum.assign(1, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        preSum.push_back(x + preSum.back());
        dp[i][i] = x;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0, j = i + len - 1; j < n; i++, j++)
        {
            dp[i][j] = get(i, j);
            for (int jj = i; jj < j; jj++)
                dp[i][j] = max(dp[i][j], get(i, jj) - dp[jj + 1][j]);
            for (int ii = i + 1; ii <= j; ii++)
                dp[i][j] = max(dp[i][j], -dp[i][ii - 1] + get(ii, j));
        }
    }

    cout << dp[0][n - 1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cout << "Case " << i + 1 << ": ";
        solve();
    }
}
```
