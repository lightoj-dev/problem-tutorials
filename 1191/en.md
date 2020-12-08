# 1191 - Bar Codes

The problem statement asks to find the number of ways to partition a `n` length array into exacly `k` contigous sub-arrays where each sub-array has length at most `m`. Let, the solution to this problem be `BC(n, k, m)`.

Now, consider the length of the first sub-array in our partition. Suppose, it's length is `x` and obviously it's in the range `[1, m]`. What's left to build a correct solution? We have the remaining `n-x` length of the array which we should partition into `k-1` contigous sub-arrays. Sounds familiar? Yes, it's exactly the same problem but with different constraints. After we fix `x` as the length of the first sub-array, we can solved the remaining problem in `BC(n-x, k-1, m)` ways.

At this point, we know our solution will look something like this:
```c++
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
- Invalid state: We are visiting some states (here the tuple (n, k, m) defines the "state" of the problem) that are invalid. For example, `n = 5`, `k = 1` and `m = 7`. From this state, when `x = 6`, we are calling `B(-1, 0, 7)` which is an invalid state. Also, we are allowing `k` to go negative, which is an invalid state too. The simplest way to resolve this is to `return 0` when we have reached an invalid state.
```c++ 
    if (n < 0 || k < 0) return 0;
```
- Base case: what's a base case? It's the simplest state of the problem, which can't be reduced any more. Notice that, `n < 0` is an invalid state. It makes sense to make `n = 0` a base case. `n = 0` means we have no array left to be partitioned. How many ways are there to partition an array of length `0` into `0` sub-arrays? Exactly `1`. However, if we see that `k != 0`, it means we still have some sub-array(s) left to be covered from the zero length array! There is no way to do that. So, we can add this piece of code after checking for invalid states:
```c++ 
    if (n == 0) {
        if (k == 0) return 1;
        return 0;
    }
```

At this point, our function `BC(n, k, m)` correctly solves the problem. If we submit the solution to online judge, it will get `Time Limit Exceeded`. It's because we are computing the solution for same instances (or you can say same states) of the problem again and again. We are not saving this value somewhere, so that we can use it later. This is where `Dynamic Programming` enters. Dynamic Programming problems must satisfy two properties. Let's see if our problem satisfies those.
- Optimal Substructure Property
- Overlapping Subproblems
