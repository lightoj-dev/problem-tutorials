# Positive Negative Sign #
---
## Solution

The problem statement has confirmed that `n = 2*m`. Which means that the series is __always possible__ to be split up in _pairs_. Let's observe the `series` for example of `n = 12` and `m = 3` :
```
Series  = - 1 - 2 - 3 + 4 + 5 + 6 - 7 - 8 - 9 + 10 + 11 + 12
        = (4-1) + (5-2) + (6-3) + (10-7) + (11-8) + (12-9)
        = 3 + 3 + 3 + 3 + 3 + 3
        = 3 * 6
        = 18
```
In the above observation, we can see that each pair produced _3_ and here `3 = m`. More clearly, `i-th positive number` + `i-th negative number` = `m`. Examples: 1st positive number is `4` and 1st negative number is `-1` and `4 + (-1) = 3`. And since the problem has stated that `n = 2*m`, we are sure to find a `i-th postive number` for a corresponding `i-th negative number`. Also, _3_ has occured _6_ times where, `6 = 12/2 = n/2`. So, the `sum = 18 = 6*3 = (n/2)*m`.

__Caution__ : Remember, we need `long` or similar data type that can hold integer values more than 10<sup>9</sup> because even if `n` and `m` alone does not need any data type more than 10<sup>9</sup>, but `n*m` does!

The above implementation is `accepted`.

## Solution in C

```c
#include <stdio.h>
int main()
{
    int t;
    long n, m, sum;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%ld %ld", &n, &m);
        sum = (n / 2) * m;
        printf("Case %d: %ld\n", i, sum);
    }
    return 0;
}
```