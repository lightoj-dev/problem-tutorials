# LOJ 1191 - Bar Codes

The problem statement asks to find the number of ways to partition a `n` length array into exacly `k` contiguous sub-arrays such that each sub-array has length at most `m`. Let, the solution to this problem be `BC(n, k, m)`.

Now, consider the length of the first sub-array in our partition. Suppose, it's length is `x` and obviously it's in the range `[1, m]`. What's left to build a correct solution? We have the remaining `n-x` length of the array which we should partition into `k-1` contiguous sub-arrays. Sounds familiar? Yes, it's exactly the same problem but with different constraints. After we fix `x` as the length of the first sub-array, we can solve the remaining problem in `BC(n-x, k-1, m)` ways.

At this point, we know our solution will look something like this:
```cpp
typedef long long LL;
LL BC(int n, int k, int m) {
  LL ans = 0;
  for (int x = 1; x <= m; x++) {
      ans += BC(n-x, k-1, m);
  }
  return ans;
}
```
There are two things that still need to be handled before the function correctly solves the problem:
- **Invalid state**: We are visiting some states (here the tuple (n, k, m) defines the "state" of the problem) that are invalid. For example, from the state `BC(5, 1, 7)`, when `x = 6`, we are calling `BC(-1, 0, 7)` which is an invalid state. Also, we are allowing `k` to go negative, which is an invalid state too. The simplest way to resolve this is to `return 0` when we have reached an invalid state.
```cpp 
if (n < 0 || k < 0) return 0;
```
- **Base case**: what's a base case? It's the simplest state of the problem, which can't be reduced any more. Notice that, `n < 0` is an invalid state. It makes sense to make `n = 0` a base case. `n = 0` means we have no array left to be partitioned. How many ways are there to partition an array of length `0` into `0` sub-arrays? Exactly `1`. However, if we see that `k != 0`, it means we still have some sub-array(s) left to be covered from the zero length array! There is no way to do that. So, we can check for base case after checking for invalid states.
```cpp 
if (n == 0) {
  if (k == 0) return 1;
  return 0;
}
```
At this point, our function `BC(n, k, m)` correctly solves the problem. 
```cpp
LL BC(int n, int k, int m) {
  if (n < 0 || k < 0) return 0;
  if (n == 0) {
    if (k == 0) return 1;
    return 0;
  }
  
  if (dp[n][k][m] != -1) return dp[n][k][m];
  
  LL ans = 0;
  for (int x = 1; x <= m; x++) {
    ans += BC(n-x, k-1, m);
  }
  return dp[n][k][m] = ans;
}
```
If we submit the solution using this function to online judge, it will get `Time Limit Exceeded`. It's because we are computing the solution for same instances (or you can say same states) of the problem again and again. We are not saving this value somewhere, so that we can use it later. 

This is where `Dynamic Programming` enters. Any Dynamic Programming problem satisfy two properties. Let's see if our problem satisfies those.
- Optimal Substructure Property: this is basically a mouthful way of saying that a problem can be solved recursively. We can see from our work above that this problem satisfies this property.
- Overlapping Subproblems: this means the recursion may visit the same state more than once. For example, in this problem, from `BC(5, 3, 2)` we can reach `BC(4, 2, 2)` and from `BC(4, 2, 2)` we can reach `BC(2, 1, 2)`. Also, from `BC(5, 3, 2)` we can reach `BC(3, 2, 2)` and from `BC(3, 2, 2)` we can reach `BC(2, 1, 2)`. So, from a single instance of the problem `BC(5, 3, 2)`, we are visiting the state `BC(2, 1, 2)` twice (and may be much more times). So, we can say that this problem has overlapping subproblems.

Now, when we visit a state for the first time, we actually solve the problem and save the result somewhere. After that, every time we visit this state we will immediately return the result, instead of breaking down into smaller problems and calculating the result from them.

To save the results for a state, we will need a 3-D array `dp[][][]`. At the start of the program, we will assign `-1` to each position of the dp table. When returning from the function, we just have to assign the result to `dp[n][k][m]`. The solution to our problem is always non-negative. So, when we reach a **valid non-base case** state `BC(n, k, m)`, if we see that `dp[n][k][m]` is `-1`, it means we did not solve the problem for this state before. In that case, we will proceed to solve the problem and save the result in dp table. The next time we visit `BC(n, k, m)`, `dp[n][k][m]` will be something other than `-1`. We can say at this moment that, we visited this state before, the solution to this state is dp[n][k][m]`.

There are in total `O(N^3)` states and `O(N^4)` transitions where `N <= 50`. The full solution will be:

### C++
-----
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 51;

LL dp[MAXN][MAXN][MAXN];
LL BC(int n, int k, int m) {
  if (n < 0 || k < 0) return 0;
  if (n == 0) {
    if (k == 0) return 1;
    return 0;
  }
  
  if (dp[n][k][m] != -1) return dp[n][k][m];
  
  LL ans = 0;
  for (int x = 1; x <= m; x++) {
    ans += BC(n-x, k-1, m);
  }
  return dp[n][k][m] = ans;
}

int main() {
  memset(dp, -1, sizeof dp);
  
  int t;
  cin >> t;
  
  for (int ti = 1; ti <= t; ti++) {
    int n, k, m;
    cin >> n >> k >> m;
    cout << "Case " << ti << ": " << BC(n, k, m) << "\n";
  }
  
  return 0;
}
```
