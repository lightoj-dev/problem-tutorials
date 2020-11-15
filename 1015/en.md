# LOJ 1015 - Brush (I)

In this problem, you will be given `T` test cases. Each test case begins with a blank line followed by an integer `N`. The next line contains `N` space-separated integers. Your task is to print out the sum of those `N` integers, ignoring any negative integers.  

The problem is pretty straightforward. However, some people might find it difficult to get an `Accepted` verdict. The reason could be one of the following:

1. Considering negative integers during summation
2. Failing to provide proper output format
3. Missing new line on each line

If you are still stuck with this problem, check the codes below:

### C
-----
```c
#include <stdio.h>
int main() {
  int T, N, num, sum;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf("%d", &N);
    sum = 0;
    for (int j = 1; j <= N; j++) {
      scanf("%d", &num);
      // negative number should be ignored, zero does not affect the sum
      if (num > 0) {
        sum += num;
      }
    }
    printf("Case %d: %d\n", i, sum);
  }
  return 0;
}
```

### Java
-----
```java
package com.loj.volume;

import java.util.Scanner;

class Brush {
  public static void main(String[] args) throws Exception {
    Scanner input = new Scanner(System.in);
    int T = input.nextInt();
    for (int i = 1; i <= T; i++) {
      int N = input.nextInt();
      int num, sum = 0;
      for (int j = 1; j <= N; j++) {
        num = input.nextInt();
        // negative number should be ignored, zero does not affect the sum
        if (num > 0) {
          sum += num;
        }
      }
      System.out.printf("Case %d: %d\n", i, sum);
    }
  }
}
```
