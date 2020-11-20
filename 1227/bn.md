# LOJ 1227 - Boiled Eggs

**[Problem](http://lightoj.com/volume_showproblem.php?problem=1227):** তোমাকে **n** সংখ্যক ডিম দেয়া হল। সর্বোচ্চ কতটি ডিম তুমি একসাথে নিয়ে সিদ্ধ করতে পারবে? তুমি **P** এর চেয়ে বেশি সংখ্যক ডিম নিতে পারবেনা এবং তোমার নেয়া ডিমগুলোর মোট ওজন **Q** গ্রামের চেয়ে বেশি হতে পারবেনা।

_Time limit: 500 ms_ 

_ইনপুট শুরু হবে পূর্ণ সংখ্যা T(≤ 100) দিয়ে যা টেস্টকেসের সংখ্যা নির্দেশ করবে._

_প্রতিটা কেস শুরু হবে তিনটা পূর্ণসংখ্যা n (1 ≤ n ≤ 30), P (1 ≤ P ≤ 30) এবং Q (1 ≤ Q ≤ 30) দিয়ে। পরবর্তী লাইনে n সংখ্যক ধন্যাত্মক পূর্ণসংখ্যা(10 এর বড় নয়) ঊর্ধ্বক্রমে সাজানো থাকবে। এই সংখ্যাগুলো একেকটা ডিমের ওজন নির্দেশ করবে।_

**যেহেতু n সংখ্যক ডিমগুলোর ওজন ইনপুটে ছোট থেকে বড় ক্রমে সাজানো থাকবে, তাই এদের মান অ্যারের ভিতরে রেখে অ্যারেকে sort করার প্রয়োজন নেই।** 

আমরা একটি sum variable নিয়ে এর মধ্যে একেকটা ডিমের ওজন যোগ করতে থাকব যতক্ষণ পর্যন্ত না sum এর মান **Q** এর চেয়ে বেশি হওয়ার উপক্রম হয়। আমরা একটি counter variable দিয়ে কতগুলো ডিম এ পর্যন্ত নেয়া হয়েছে তার হিসাব রাখব। counter variable এর মান যতক্ষণ না **P** এর বেশি হওয়ার উপক্রম হচ্ছে, ততক্ষণ আমরা এক করে বাড়াতে থাকব।  

###### যদিও [এই O(n^2) solution]( https://github.com/Arfaqur-Rahman/cp/blob/master/LightOJ/1227%20-%20Boiled%20Eggs.cpp ) `Accepted` হয়, এর চেয়ে ভাল উপায়ে আমরা প্রবলেমটি সলভ করতে পারি। একটি O(n) solution নিচে আলোচনা করা হল।

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
            cin >> x;
            
            if(counter + 1 <= P && sumOfWeight + x <= Q){ // counter+1<=P নিশ্চিত করে মোট ডিমসংখ্যা যেন কখনো P এর চেয়ে বেশি না হয়। sumOfWeight+x<=Q নিশ্চিত করে ডিমের মোট ওজন যেন কখনো Q এর বেশি না হয়।
              sumOfWeight += x;                           // sumOfWeight variable এর মাধ্যমে আমরা ডিমের মোট ওজনের হিসাব রাখছি 
              counter++;                                  // counter variable এর মাধ্যমে আমরা এ পর্যন্ত নেয়া মোট ডিমসংখ্যার হিসাব রাখছি 
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
            
            if(counter + 1 <= P && sumOfWeight + x <= Q){ // counter+1<=P নিশ্চিত করে মোট ডিমসংখ্যা যেন কখনো P এর চেয়ে বেশি না হয়। sumOfWeight+x<=Q নিশ্চিত করে ডিমের মোট ওজন যেন কখনো Q এর বেশি না হয়।
              sumOfWeight += x;                 // sumOfWeight variable এর মাধ্যমে আমরা ডিমের মোট ওজনের হিসাব রাখছি।
              counter++;                        // counter variable এর মাধ্যমে আমরা এ পর্যন্ত নেয়া মোট ডিমসংখ্যার হিসাব রাখছি। 
            }
            
       }
      
      System.out.println("Case " + caseno + ": " + counter);
    }
  }
}
```
Happy Coding!

Written by: [Md. Arfaqur Rahman](https://www.facebook.com/arfaqur.rahman.31/)
