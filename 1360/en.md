# Tutorial for Skyscraper

## Problem Summary

We are given $N$ tasks (or skyscraper building phases), each characterized by a starting time $a$, a duration $b$, and a profit or value $c$. The task finishes at time $a + b$. We want to choose a subset of non-overlapping tasks such that the total profit is maximized. A new task can start exactly at or after the finish time of a chosen task.

This is a classic variation of the **Weighted Job Scheduling** problem.

## Finding the DP State and Recurrence Relation

To solve this, we first sort the tasks based on their starting times in ascending order.

Let `DP[i]` be the maximum profit we can achieve by considering a subset of tasks from index $i$ to $N-1$.

**Base Case:**

- `DP[N] = 0` (If there are no tasks left to consider, the profit is 0).

For any task at index $i$, we have two choices:

1. **Skip the current task:** The maximum profit will just be the best we can do using the remaining tasks, which is `DP[i+1]`.
2. **Take the current task:** We gain its profit $c$, but we cannot take any tasks that overlap with it. We must find the next valid task `ind` that starts on or after $a + b$. The profit would then be $c + DP[ind]$.

So, 

$$DP[i] = \max(DP[i+1], c_i + DP[ind])$$

## Optimizing with Binary Search

Finding the next non-overlapping task (`ind`) using a simple `for` loop would take $O(N)$ time per state, leading to a Time Limit Exceeded (TLE) overall time complexity of $O(N^2)$.

Since we have already sorted our tasks by their starting times, We can optimize the search for `ind` down to $O(\log N)$ using **Binary Search** (`lower_bound` in C++).

For a task $i$ ending at $nxtfloor = a_i + b_i$, we query the sorted start times to find the first index `ind > i` where $start[ind] \ge nxtfloor$.

## Code Explanation

- **`choto(v)`**: A macro for `sort(v.begin(), v.end())`. Since our vectors are structured as `{start, duration, profit}`, sorting the 2D vector automatically sorts all tasks based on their starting times.
- **`start` array**: We isolate the starting times of all tasks into a single 1D vector. This provides a clean array to run our binary search on.
- **`lower_bound(...) - start.begin()`**: This effectively acts as our binary search. It looks from `i + 1` to the end of the `start` array for the first task that begins on or after `nxtfloor` ($a + b$). It returns the index `ind` of that task.
- **`dp` array**: We iterate backwards from $N-1$ down to 0, populating our $DP$ table using the recurrence relation. `dp[0]` will ultimately hold the maximum profit considering all tasks.

## Complexity

- **Time Complexity:** $O(N \log N)$ per test case. Sorting the array takes $O(N \log N)$. Populating the DP array takes $N$ steps, and each step performs a binary search taking $O(\log N)$ time.
- **Space/Memory Complexity:** $O(N)$ for storing the tasks in the 2D vector, the 1D `start` array, and the 1D `dp` array.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pi acos(-1.0)
#define pb push_back
#define sqrt(x) sqrtl(x)
#define pll pair<ll, ll>
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define choto(x) sort((x).begin(), (x).end())
#define boro(x) sort((x).rbegin(), (x).rend())
#define all(x) (x).begin(), (x).end()
#define in(x)          \
    for (auto &it : x) \
        cin >> it;
#define allout(x)          \
    for (auto &it : x)     \
        cout << it << " "; \
    cout << endl
#define out(y, a, n)            \
    for (ll i = a; i <= n; i++) \
        cout << y[i] << " ";    \
    cout << endl
#define vsum(x) accumulate((x).begin(), (x).end(), 0LL)
#define vec2d(name, n, m, val) vector<vector<ll>>(name)((n), vector<ll>((m), (val)))
#define fix(n, val) fixed << setprecision(n) << val
#define padding0(n, val) setw(n) << setfill('0') << val
#define dbug(x) cout << #x << " -> " << x << endl;
#define ff first
#define ss second
#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

void Rupalisaurus()
{
    ll n;
    cin >> n;
    vec2d(v, n, 3, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    // Sort tasks by start time
    choto(v);

    vector<ll> start(n);
    for (ll i = 0; i < n; i++)
    {
        start[i] = v[i][0];
    }

    // DP array to store max profit from index i to n-1
    vector<ll> dp(n + 1, 0);
    ll a, b, c;
    ll nxtfloor;
    ll ind;

    // Process from right to left
    for (ll i = n - 1; i >= 0; i--)
    {
        a = v[i][0];
        b = v[i][1];
        c = v[i][2];

        nxtfloor = a + b; // Finish time

        // Binary search to find the next compatible task
        ind = lower_bound(start.begin() + i + 1, start.end(), nxtfloor) - start.begin();

        // Transition: max(Skip current, Take current + max profit from next valid)
        dp[i] = max(dp[i + 1], c + dp[ind]);
    }

    cout << dp[0] << endl;
}

int32_t main()
{
    fast_io;

    ll t, tc = 0;
    if (cin >> t) {
        while (t--)
        {
            cout << "Case " << ++tc << ": ";
            Rupalisaurus();
        }
    }
    return 0;
}
```
