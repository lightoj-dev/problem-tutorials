# LOJ 1001 - Opposite Task

You are given a number `n`. If `n` can be written as addition of two positive integers such as, `n = a+b`  then print the value of `a` and `b`. Any value of `a` and `b` that follow the equation is accepted.

### C
-----
```c
#include <stdio.h>
int main()
{
    int test, num;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &num);
        if(num > 10){
            printf("%d ", 10);
            num = num - 10;
        }
        else printf("0 ");
        printf("%d\n", num);
    }
    return 0;
}

```
