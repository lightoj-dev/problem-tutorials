# LOJ 1000 - Greeting on LightOJ

It is the easiest problem on LightOJ volumes. All you have to do is print out the sum of input `a` and `b` on each case. There is nothing tricky about it.

But still some people can't get `Accepted` verdict because of not following the proper output format.

1. Make sure you have printed newline on each line
2. Make sure you have same output as the sample output on the problem descriptin, take a look at case number.
3. Make sure you have added right amount of spaces on the output.

If you are still stuck with this problem, check the codes below:

### C
-----
```c
#include <stdio.h>

int main() {
  int cases, caseno;
  scanf("%d", &cases);
  for (caseno = 1; caseno <= cases; ++caseno) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Case %d: %d\n", caseno, a + b);
  }
  return 0;
}
```

### Java
-----
```java
package com.loj.volume;

import java.util.Scanner;

class GreetingsFromLoj {
  public static void main(String[] args) throws Exception {
    Scanner scanner = new Scanner(System.in);
    int cases = scanner.nextInt();
    for (int caseno = 1; caseno <= cases; ++caseno) {
      int a = scanner.nextInt();
      int b = scanner.nextInt();
      System.out.println("Case " + caseno + ": " + (a + b));
    }
  }
}
```

### Python 2
-----
```python
for i in xrange(int(raw_input())):
  print "Case %i: %i" % (i + 1, sum(map(int, raw_input().split())))
```
