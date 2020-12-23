# LOJ 1053 - Higher Math

In this problem, you will be given `T` test cases. Each test case contains three space-separated integers with values ranging from 1 to 40000. These integers denote the lengths of the sides of a triangle. Your task is to determine whether the triangle is right angled.

You can use the `Pythagoras' Theorem` to solve this problem. *Pythagoras' Theorem* states that:
```
In a right angled triangle, the square of the hypotenuse is equal to the sum of the squares of the other two sides.
```
[Here](https://www.mathsisfun.com/pythagoras.html) is a tutorial for some additional explanation.

The problem is fairly simple. However, some people might find it difficult to get an `Accepted` verdict. The reason could be one of the following:

1. Forgetting to consider the length of the longest side as the hypotenuse
2. Failing to provide proper output format
3. Missing new line on each line

If you are still stuck with this problem, check the codes below:

### C++
-----
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, sides[3];
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cin >> sides[0] >> sides[1] >> sides[2];
    sort(sides, sides + 3);
    int hypo_square = sides[2] * sides[2];
    int other_square = sides[0] * sides[0] + sides[1] * sides[1];
    cout << "Case " << i << ": " << (hypo_square == other_square ? "yes" : "no") << "\n";
  }
  return 0;
}
```

### Java
-----
```java
package com.loj.volume;

import java.util.Scanner;
import java.util.Arrays;

class HigherMath {
  public static void main(String[] args) throws Exception {
    Scanner input = new Scanner(System.in);
    int T = input.nextInt(), sides[] = {0, 0, 0};
    for (int i = 1; i <= T; i++) {
      for (int j = 0; j < 3; sides[j] = input.nextInt(), j++);
      Arrays.sort(sides);
      int hypoSquare = sides[2] * sides[2];
      int otherSquare = sides[0] * sides[0] + sides[1] * sides[1];
      System.out.printf("Case %d: %s\n", i, (hypoSquare == otherSquare ? "yes" : "no"));
    }
  }
}
```
