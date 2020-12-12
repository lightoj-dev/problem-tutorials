# LOJ 1182 - Parity

In this problem, you will be given `T` test cases. Each test case contains an integer `n`. Your task is to determine whether `n` has odd parity (odd number of set bits in its binary representation) or even parity (even number of set bits in its binary representation). Note: In a binary number, 0s are called `unset bits` and 1s are called `set bits`.

One approach to solve this problem is to use the built-in function `__builtin_popcount` of `C++` or `bitCount` of `Java`. 

A second approach is to loop through all the bits of `n` and compute the total number of set bits. [This](https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/tutorial/) and [this](https://www.topcoder.com/community/competitive-programming/tutorials/a-bit-of-fun-fun-with-bits/) will help you grasp the basics of bit manipulation for implementing this approach.

A much better and optimized solution is in the use of **Brian Kernighan's Algorithm**. [Here](https://medium.com/@sanchit3b/brian-kernighans-algorithm-9e0ca5989148) is a tutorial to help you understand the algorithm.

This is a good-first problem to get you started with bit manipulation. However, some people might find it difficult to get an `Accepted` verdict. The reason could be one of the following:

1. Errors with bitwise operations
2. Failing to provide proper output format
3. Missing new line on each line

If you are still stuck with this problem, check the codes below:

### C++
-----
**Approach #1**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int cases, num;
  cin >> cases;
  for (int i = 1; i <= cases; i++) {
    cin >> num;
    cout << "Case " << i << ": " << ((__builtin_popcount(num) & 1) ? "odd" : "even") << "\n";
  }
  return 0;
}
```

**Approach #2**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int cases, num, ones;
  cin >> cases;
  for (int i = 1; i <= cases; i++) {
    cin >> num;
    ones = 0;
    for (int j = 0; j <= 31; j++) {
      if (num & (1 << j)) {
        ones++;
      }
    }
    cout << "Case " << i << ": " << (ones & 1 ? "odd" : "even") << "\n";
  }
  return 0;
}
```

**Approach #3**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int cases, num, ones;
  cin >> cases;
  for (int i = 1; i <= cases; i++) {
    cin >> num;
    ones = 0;
    for (; num; num = num & (num - 1), ones++);
    cout << "Case " << i << ": " << (ones & 1 ? "odd" : "even") << "\n";
  }
  return 0;
}
```

### Java
-----
**Approach #1**
```java
package com.loj.volume;

import java.util.Scanner;

class Parity {
  public static void main(String[] args) throws Exception {
    Scanner input = new Scanner(System.in);
    int cases = input.nextInt(), num;
    for (int i = 1; i <= cases; i++) {
      num = input.nextInt();
      System.out.println("Case " + i + ": " + ((Integer.bitCount(num) & 1) > 0 ? "odd" : "even"));
    }
  }
}
```

**Approach #2**
```java
package com.loj.volume;

import java.util.Scanner;

class Parity {
  public static void main(String[] args) throws Exception {
    Scanner input = new Scanner(System.in);
    int cases = input.nextInt(), num, ones;
    for (int i = 1; i <= cases; i++) {
      num = input.nextInt();
      ones = 0;
      for (int j = 0; j <= 31; j++) {
        if ((num & (1 << j)) > 0) {
          ones++;
        }
      }
      System.out.println("Case " + i + ": " + ((ones & 1) > 0 ? "odd" : "even"));
    }
  }
}
```

**Approach #3**
```java
package com.loj.volume;

import java.util.Scanner;

class Parity {
  public static void main(String[] args) throws Exception {
    Scanner input = new Scanner(System.in);
    int cases = input.nextInt(), num, ones;
    for (int i = 1; i <= cases; i++) {
      num = input.nextInt();
      ones = 0;
      for (; num > 0; num = num & (num - 1), ones++);
      System.out.println("Case " + i + ": " + ((ones & 1) > 0 ? "odd" : "even"));
    }
  }
}
```
