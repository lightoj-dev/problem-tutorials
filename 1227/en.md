# LOJ 1227 - Boiled Eggs

**[Problem](http://lightoj.com/volume_showproblem.php?problem=1227):** You are given **n** eggs. In one trial, you need to boil the maximum number of eggs. You cannot take more than **P** eggs and the total weight of the eggs cannot be more than **Q** gm.

_Time limit: 500 ms_

_Input starts with an integer T (≤ 100), denoting the number of test cases._

_Each case starts with three integers n (1 ≤ n ≤ 30), P (1 ≤ P ≤ 30) and Q (1 ≤ Q ≤ 30). The next line contains n positive integers (not greater than 10) in non-descending order. These integers denote the weight of the eggs in gm._

**As the weight of each egg will be given in non-decreasing order, there is no need to store their values in an array and sort them.** 

Using a sum variable to compare the total weight with Q and a counter variable will suffice. 
In the end, we need to print the value of the counter variable.

###### Although [this O(n^2) solution]( https://github.com/Arfaqur-Rahman/cp/blob/master/LightOJ/1227%20-%20Boiled%20Eggs.cpp ) gets accepted, this approach is not recommended. If constraints(T and n) were bigger, this approach might cause you to encounter a TLE.

### C++
-----
```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
    int testcase; 
    cin>>testcase;
    
    for(int t=1; t<=testcase; t++){
        int n, P, Q; 
        cin >> n>> P>> Q;

        int sumOfWeight= 0, counter=0;
        for(int i = 1; i <= n; i++ ){
            int x; 
            cin>>x;
            
            if(i <= P && sumOfWeight + x <= Q){ // i<=P ensures that number of eggs never exceeds P. sumOfWeight+x<=Q ensures that total weight of eggs never exceeds Q
              sumOfWeight += x;                 // With the sumOfWeight variable, we are keeping track of the total weight of the eggs
              counter++;                        // counter variable keeps track of the number of eggs
            }
            
        }
        cout << "Case " << t << ": " << counter << endl;
    }
}
```

### Java
-----
```java
package com.loj.volume;

import java.util.Scanner;

class BoiledEggs {
  public static void main(String[] args) throws Exception {
    Scanner scanner = new Scanner(System.in);
    int cases = scanner.nextInt();
    for (int caseno = 1; caseno <= cases; ++caseno) {
      int n = scanner.nextInt();
      int P = scanner.nextInt();
      int Q = scanner.nextInt();

      int sumOfWeight= 0, counter=0;
      for(int i = 1; i <= n; i++ ){
            int x = scanner.nextInt();
            
            if(i <= P && sumOfWeight + x <= Q){ // i<=P ensures that number of eggs never exceeds P. sumOfWeight+x<=Q ensures that total weight of eggs never exceeds Q
              sumOfWeight += x;                 // With the sumOfWeight variable, we are keeping track of the total weight of the eggs
              counter++;                        // counter variable keeps track of the number of eggs
            }
            
       }
      
      System.out.println("Case " + caseno + ": " + counter);
    }
  }
}
```
Happy Coding!

Written by: [Md. Arfaqur Rahman](https://www.facebook.com/arfaqur.rahman.31/)
