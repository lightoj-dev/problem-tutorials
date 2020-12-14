#### LOJ 1088 - Points in Segments

# Summary

In this problem, you will be given an array of non-negative integers of size `N`, All the integers are distinct and the array will be given in a sorted manner. You will be given `Q` queries also.

In each query, you will be given two integers `L` and `R`. You need to find out the number of points that lie in segment `[L,R]` (`[L,R]` is a segment that starts from point `L` and ends on point `R`).

#### Solution
## Brute force approach (Time Limit Exceeded)

For each query, you can simply run a linear loop over all the integers of the array and find out whether each of them lies inside the query segment or not. The overall time complexity of this approach is `O(Q x N)` where `Q` denotes the number of queries and `N` is the size of the array.

As `Q` can be up to `5x10^4` and `N` can be up to `10^5`, `QN` can be up to `5x10^9`. There are 5 test cases too! So overall, there can be up to `2.5x10^10` operations and it would take roughly `250` seconds! Too much!

## Efficient approach with binary search (Accepted)

Most important observation:

- Our given array is SORTED.

We can make use of this fact in order to improve our runtime. In a sorted array of numbers, you can easily find how many numbers lie in a segment from `L` to `R` from the upper bound of `R` - lower bound of `L`. upper bound and lower bound can be easily found out from a sorted array in logarithmic time. It reduces the query handling runtime to `O(logN)`.

For example, let's consider a random test case:

```
array = {1,2,2,2,3,4,4,5,6,7,7,7,10,10,11,16}
L = 3
R = 12

The query asks us to find out how many numbers are there starting from L = 3 (inclusive) to R = 12 (inclusive).

upper_bound of R = 12 in array is 15 (It's the index)
lower_bound of L = 3 in array is 4

So, the final answer is 15 - 4 = 11
```

Time Complexity: `O(Q * log(N))` per test case
Memory Complexity: `O(N)` per test case

#### Code
## C++

```
#include <bits/stdc++.h>
using namespace std;
#define MAX 100006

int arr[MAX];

int main()
{
    int t, n, Q, cs = 1;
    scanf("%d", &t);
    while(t--)
    {
       scanf("%d %d", &n, &Q);
       for(int i=0;i<n;i++) scanf("%d",&arr[i]);
       printf("Case %d:\n",cs++);
       while(Q--)
       {
           int L,R;
           scanf("%d %d",&L,&R);
           int ub = upper_bound(arr,arr+n,R) - arr; /// O(log2(N))
           int lb = lower_bound(arr,arr+n,L) - arr; /// O(log2(N))
           printf("%d\n",ub - lb);
       }
    }
    return 0;
}
```
