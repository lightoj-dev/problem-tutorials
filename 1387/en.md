# LOJ 1387 - Setu

In this problem, you will be given `T` test cases. Each test case begins with an integer `N` followed by `N` lines. Each line contains either of the strings:
- `donate K`, where `K` is an integer ranging from 100 to 100000 inclusive, or
- `report`

Note that, both of `T` and `N` can be at most `100`. 

Now, keep an integer variable `sum` with initial value as `0`. When you receive the string `donate K`, your task is to add `K` to the `sum`. And, when you receive the string `report`, your task is to print out the value of the `sum`.

The problem is pretty straightforward. However, some people might find it difficult to get an `Accepted` verdict. The reason could be one of the following:

1. Failing to provide proper output format
2. Missing new line on each line

If you are still stuck with this problem, check the codes below:

### C++
-----
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, N, K, sum;
  string operation;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cin >> N; sum = 0;
    cout << "Case " << i << ":\n";
    for (int j = 1; j <= N; j++) {
      cin >> operation;
      if (operation == "donate") {
        cin >> K;
        sum += K;
      } else {
        cout << sum << "\n";
      }
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

class Setu {
  public static void main(String[] args) throws Exception {
    int T, N, sum;
    String operation;
    Scanner input = new Scanner(System.in);
    T = input.nextInt();
    for (int i = 1; i <= T; i++) {
      N = input.nextInt(); sum = 0;
      System.out.printf("Case %d:\n", i);
      for (int j = 1; j <= N; j++) {
        operation = input.next();
        if (operation.equals("donate")) {
          sum += input.nextInt();
        } else {
          System.out.printf("%d\n", sum);
        }
      }
    }
  }
}
```
