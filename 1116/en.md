# LOJ 1116 - Ekka Dokka #
---

Input starts with an integer _T (≤ 10000)_, denoting the number of test cases.

Each case contains an integer _W (2 ≤ W < 2<sup>63</sup>)_. And W will not be a power of 2.

For each case, print the case number first. After that print `Impossible` if they can't buy their desired cake. If they can buy such a cake, you have to print `N` and `M`. If there are multiple solutions, then print the result where **M is as small as possible**.

This is just a simple implementation problem. First we have to determine wether `W` is `even` or `odd` simply by checking `W % 2 = 0 or not`. If `W is odd`, we already realize that it is `Impossible` for such `N` and `M` to exist. But when it is not, there can be both single or multiple solutions such that `N * M = W`. For example: if `W = 10`, the only solution is `N = 5` and `M = 2`. But in case of `W = 12`, `(N,M) = {(6,2),(3,4)}`. Now there are 2 conditions:

 `1. N must be odd. M must be even`.

 `2. M must be as small as possible`.

 Focusing on `Condition 2`, the equation can be solved as `(N/a)*(M*a) = W` where to make `a` as big as possible so that `M` becomes smaller as well as `(N/a)` becomes an `odd` number. To solve it, we will keep assigning `N = N/2` until it is an `odd` number and we will be also assigning `M = M/2` upto how many times `N` can be divided until is an `odd` number.

 Remember, you need `long` data type or similar data type that can hold an integer value of _2<sup>63</sup>_

 The above implementation is `accepted`.  

## Solution in C ##

```c
#include <stdio.h>

int main()
{
    int t;
    long n, m, w;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%ld", &w);
        if (w % 2 == 0)
        {
            n = w / 2;
            m = 2;
            while (n % 2 == 0)
            {
                n /= 2;
                m *= 2;
            }
            printf("Case %d: %ld %ld\n", i, n, m);
        }
        else
            printf("Case %d: Impossible\n", i);
    }
    return 0;
}
```