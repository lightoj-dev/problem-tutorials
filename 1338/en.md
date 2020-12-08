# LOJ 1338 - Hidden Secret!

In this problem, you are given `T` test cases. Each case starts with two lines. Each line contains a name consisting of upper/lower case English letters and spaces. You can assume that the length of any name is between 1 and 100 (inclusive). For each case, you need to print the case number and the string `Yes` if one name is hidden into another. Otherwise, you need to print the string `No`.

This is fairly an easy problem and you can approach several ways to solve this. One approach is to take advantage of some available library functions and the steps are:
1. Take the two strings and convert them to lowercase 
2. Then, remove spaces from the strings
3. Sort the strings (characters in the string)
4. Finally check if the strings are equal or not

If you are still stuck with this problem, check the codes below:

### C++
-----
```cpp
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {
  int t;
  string a, b;
  cin >> t;
  getline(cin, a);
  for (int i = 0; i < t; i++) {
    getline(cin, a);
    getline(cin, b);
    
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    
    a.erase(remove(a.begin(), a.end(), ' '), a.end());
    b.erase(remove(b.begin(), b.end(), ' '), b.end());
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    if (a == b) {
      cout << "Case " << i + 1 << ": Yes\n";
    } else {
      cout << "Case " << i + 1 << ": No\n";
    }
  }
  return 0;
}
```

### Java
-----
```java
import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
  public static void main (String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    sc.nextLine();
    for (int i = 0; i < t; i++) {
      String a = sc.nextLine();
      String b = sc.nextLine();
      
      a = a.toLowerCase();
      b = b.toLowerCase();
      
      a = a.replaceAll("\\s+", "");
      b = b.replaceAll("\\s+", "");
      
      char a_array[] = a.toCharArray();
      char b_array[] = b.toCharArray();
      
      Arrays.sort(a_array);
      Arrays.sort(b_array);
      
      if (Arrays.equals(a_array, b_array)) {
        System.out.println("Case "+ (i + 1) +": Yes");
      } else {
        System.out.println("Case "+ (i + 1) +": No");
      }
    }
  }
}
```
