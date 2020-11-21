# LOJ 1227 - Boiled Eggs

**[Problem](http://lightoj.com/volume_showproblem.php?problem=1227):** You are given **n** eggs. In one trial, you need to boil the maximum number of eggs. You cannot take more than **P** eggs and the total weight of the eggs cannot be more than **Q** gm.

_Time limit: 500 ms_

_Input starts with an integer `T` (≤ 100), denoting the number of test cases._

_Each case starts with three integers `n` (1 ≤ n ≤ 30), `P` (1 ≤ P ≤ 30) and `Q` (1 ≤ Q ≤ 30). The next line contains n positive integers (not greater than 10) in non-descending order. These integers denote the weight of the eggs in gm._

**O(n^2) Approach:** We can store the weight of each egg in an array of size n and run two for loops to check for all possible answers. This approach will take O(n) space and O(n^2) time.

**O(n) Approach:** As in the input the weight of each egg will be given in non-decreasing order, there is no need to store their values in an array and sort them. It is possible to solve the problem in O(n) time. We can use a sum variable and keep adding the weight of each egg to the sum variable until it exceeds **Q**. We need a counter variable to keep track of the number of eggs taken so far until it exceeds **P**. In the end, we need to print the value of the counter variable. This approach will take O(1) space and O(n) time.


### C++
-----
**O(n^2) Solution**
```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
    int testcase; 
    cin>>testcase;
    
    for(int t = 1; t <= testcase; t++){
        int n, P, Q; 
        cin >> n >> P >> Q;

        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        
        int mx = 0;
        for(int i = 0; i < n; i++){
        
            int counter = 0, sumOfWeight = 0;
            for(int j = i; j < n; j++){
                if(counter + 1 <= P && sumOfWeight + a[j] <= Q) { // counter+1<=P ensures that number of eggs never exceeds P. sumOfWeight+x<=Q ensures that total weight of eggs never exceeds Q
                    sumOfWeight += a[j];                          // With the sumOfWeight variable, we are keeping track of the total weight of the eggs
                    counter++;                                    // counter variable keeps track of the number of eggs
                    mx = max(mx, counter);                        // storing the maximum value of counter in mx every time
                }
                else break;
            }
            
        }
        
        cout << "Case " << t << ": " << mx << endl;
    }
}
```

**O(n) Solution**
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
            cin >> x;
            
            if(counter + 1 <= P && sumOfWeight + x <= Q){ // counter+1<=P ensures that number of eggs never exceeds P. sumOfWeight+x<=Q ensures that total weight of eggs never exceeds Q
              sumOfWeight += x;                           // With the sumOfWeight variable, we are keeping track of the total weight of the eggs
              counter++;                                  // counter variable keeps track of the number of eggs
            }
            
        }
        cout << "Case " << t << ": " << counter << endl;
    }
}
```


### Java
-----
**O(n^2) Solution**
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
 
      int[] a = new int[n];
      for(int i = 0; i < n; i++) a[i] = scanner.nextInt();
 
      int mx = 0;
      for(int i = 0; i < n; i++){
          int counter = 0, sumOfWeight = 0;
          for(int j = i; j < n; j++){
              if(counter + 1 <= P && sumOfWeight + a[j] <= Q) { // counter+1<=P ensures that number of eggs never exceeds P. sumOfWeight+x<=Q ensures that total weight of eggs never exceeds Q
                  sumOfWeight += a[j];                          // With the sumOfWeight variable, we are keeping track of the total weight of the eggs
                  counter++;                                    // counter variable keeps track of the number of eggs
                  mx = Math.max(mx, counter);                   // storing the maximum value of counter in mx every time
              }
              else break;
          }
      }
     
      System.out.println("Case " + caseno + ": " + mx);
    }
  }
}
```

**O(n) Solution**
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
            
            if(counter + 1 <= P && sumOfWeight + x <= Q){ // counter+1<=P ensures that number of eggs never exceeds P. sumOfWeight+x<=Q ensures that total weight of eggs never exceeds Q
              sumOfWeight += x;                           // With the sumOfWeight variable, we are keeping track of the total weight of the eggs
              counter++;                                  // counter variable keeps track of the number of eggs
            }
            
       }
      
      System.out.println("Case " + caseno + ": " + counter);
    }
  }
}
```

Happy Coding!

Written by: [Md. Arfaqur Rahman](https://www.facebook.com/arfaqur.rahman.31/)
