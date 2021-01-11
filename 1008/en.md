# LOJ 1008 - Fibsieve's Fantabulous Birthday #
---

In the first input, we will be given the number of test cases *T* . After that we will be given an input *S* upto *T* times, each of which represents the S-th second and we have to output which cell would light up by outputting the value of its column and row number separated by a single space.

If we take few examples from the chess board, for 25, its row number is 5 and 5 = √25. For 24, its row number is 5 and 5 = ⌈√24⌉. However, for 16, its column number is 4 and 4 = ⌈√16⌉. Similarly, for 15, its column number is 4 and 4 = ⌈√15⌉. So, if ⌈√S⌉ is an even number, the ceiling value of the square root of *S* produces the column number and if it is an odd number, it produces the row number.

For the column number of 24 it is 2 and here 2 = (closest square number to 24 ~ 24) + 1 = 25 - 24 + 1 = 2. In case of 15, its row number is 2 and 2 = (closest square number to 15 ~ 15) + 1 = 16 -15 + 1 = 2. In case of both 24 and 15, the closest square number is after them. 

But in case of 17, its column number is 5 and 5  = ⌈√17⌉ although here ⌈√17⌉ produced 5 which is an odd number and again the row number is 1 = (closest square number to 17 ~ 17) = 17 - 16 = 1. Now to determine whether the closest square number to *S* is after or before it, we can determine by whether ⌈√S⌉² - *S* > ⌈√S⌉ or not. If it is lesser than it then we know that the closest square number to *S* is before *S* and if it is greater then we know that the closest square number to *S* is after *S*. If we examine the closest square number to *S* when it is after *S*, that number is actually (⌈√S⌉ - 1)². Example: for 17, (⌈√17⌉ - 1)² = (5 - 1)² = 16 and from that, 17 - 16 = 1 which is the row number of 17.

The above implementation is `Accepted`.

## Solution in C ##

```c
#include <stdio.h>
#include <math.h>

int main()
{
    int cases;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++)
    {
        long long seconds, root, lackings, row, column;
        scanf("%lld", &seconds);
        root = ceil(sqrt(seconds * 1.0));
        lackings = root * root - seconds;
        if (lackings < root){
            row = root;
            column = lackings + 1;
        }
        else{
            column = root;
            row = seconds - (root-1) * (root-1);
        }
        if(root % 2 == 0){
            long long temp = column;
            column = row;
            row = temp;
        }
        printf("Case %d: %lld %lld\n",i, column, row);
    }

    return 0;
}
```
