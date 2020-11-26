# LOJ 1001 - Opposite Task

In this problem, you are given `T` test cases. Each test case contains an integer `n`, the value of which is `20` at max. Your task is to print out two non-negative integers `a` and `b`, such that `n = a + b`. Any values of `a` and `b` that satisfies the equation is accepted, however, neither of `a` nor `b` can be greater than `10`.

It is one of the easiest problems on LightOJ volumes. However, some people might find it difficult to get an `Accepted` verdict. The reason could be one of the following:
1. Printing a number greater than 10 
2. Failing to provide proper output format
3. Missing new line on each line

If you are still stuck with this problem, check the codes below:

### C
-----
```c
#include <stdio.h>
int main() {
  int T, n;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf("%d", &n);
    if (n > 10) {
      printf("10 %d\n", n - 10);
    } else {
      printf("0 %d\n", n);
    }
  }
  return 0;
}
```

### Java
-----
```java
package com.loj.volume;

import java.util.Scanner;

class OppositeTask {
  public static void main(String[] args) throws Exception {
    Scanner scanner = new Scanner(System.in);
    int T = scanner.nextInt(), n;
    for (int i = 1; i <= T; i++) {
      n = scanner.nextInt();
      if (n > 10) {
        System.out.printf("10 %d\n", n - 10);
      } else {
        System.out.printf("0 %d\n", n);
      }
    }
  }
}
```
