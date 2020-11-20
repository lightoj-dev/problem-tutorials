# LOJ 1225 - Palindromic Numbers (II)

In this problem, you will be given `T` test cases. Each test case contains an integer `n`. Your task is to determine whether `n` is palindromic or not. A *palindromic number* is a number which reads the same when its digits are reversed.

One possible approach to solve this problem is the literal translation of the meaning of *palindromic number* to code. And this can be achieved by taking the integer `n` as a string followed by checking equality with its reversed string. Note: `C++` and `Java`, both have built-in `reverse` function for string manipulation.

You can also keep the input as an integer and create a function to reverse that integer. [Here](https://www.java67.com/2015/08/how-to-reverse-integer-in-java-leetcode-solution.html) is a tutorial to help you understand how to reverse an integer.

Another approach to solving this problem comes from the notion that the first digit of `n` should be equivalent to its last digit, the second digit of `n` should be equivalent to its second-last digit, and this goes on till the middle digit is reached, in order for `n` to be palindromic. This approach can be easily performed by taking the integer `n` as a string.   

The problem is pretty straightforward. However, some people might find it difficult to get an `Accepted` verdict. The reason could be one of the following:

1. Logical error while reversing the integer (if you prefer to keep the checking between integers) 
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
  int cases;
  string str, rev;
  cin >> cases;
  for (int i = 1; i <= cases; i++) {
    cin >> str;
    rev = str;
    reverse(rev.begin(), rev.end());
    cout << "Case " << i << ": " << (str == rev ? "Yes" : "No") << "\n"; 
  }
  return 0;
}
```

**Approach #2**
```cpp
#include <bits/stdc++.h>
using namespace std;

int reverse(int n) {
  int m = 0;
  for (; n > 0 ; m = m * 10 + (n % 10), n /= 10);
  return m;
}

int main() {
  int cases, num;
  cin >> cases;
  for (int i = 1; i <= cases; i++) {
    cin >> num;
    cout << "Case " << i << ": " << (num == reverse(num) ? "Yes" : "No") << "\n";
  }
  return 0;
}
```

**Approach #3**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int cases, sz;
  string str;
  cin >> cases;
  for (int i = 1; i <= cases; i++) {
    cin >> str;
    sz = str.size();
    bool is_pali = true;
    for (int j = 0, k = sz - 1; j < k; j++, k--) {
      // one mismatch, no longer palindromic
      if (str[j] != str[k]) {
        is_pali = false;
        break;
      }
    }
    cout << "Case " << i << ": " << (is_pali ? "Yes" : "No") << "\n";
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

class PalindromicNumbers {
  public static void main(String[] args) throws Exception {
    Scanner input = new Scanner(System.in);
    int cases = input.nextInt();
    StringBuilder str, rev;
    for (int i = 1; i <= cases; i++) {
      str = new StringBuilder(input.next());
      rev = new StringBuilder().append(str).reverse();
      System.out.println("Case " + i + ": " + (str.toString().equals(rev.toString()) ? "Yes" : "No"));
    }
  }
}
```

**Approach #2**
```java
package com.loj.volume;

import java.util.Scanner;

class PalindromicNumbers {
  static int reverse(int n) {
    int m = 0;
    for (; n > 0 ; m = m * 10 + (n % 10), n /= 10);
    return m;
  }
  
  public static void main(String[] args) throws Exception {
    Scanner input = new Scanner(System.in);
    int cases = input.nextInt(), num;
    for (int i = 1; i <= cases; i++) {
      num = input.nextInt();
      System.out.println("Case " + i + ": " + (num == reverse(num) ? "Yes" : "No"));
    }
  }
}
```

**Approach #3**
```java
package com.loj.volume;

import java.util.Scanner;

class PalindromicNumbers {
  public static void main(String[] args) throws Exception {
    Scanner input = new Scanner(System.in);
    int cases = input.nextInt(), sz;
    String str;
    for (int i = 1; i <= cases; i++) {
      str = input.next();
      sz = str.length();
      boolean isPali = true;
      for (int j = 0, k = sz - 1; j < k; j++, k--) {
        // one mismatch, no longer palindromic
        if (str.charAt(j) != str.charAt(k)) {
          isPali = false;
          break;
        }
      }
      System.out.println("Case " + i + ": " + (isPali ? "Yes" : "No"));
    }
  }
}
```
