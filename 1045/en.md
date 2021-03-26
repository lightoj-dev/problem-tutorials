# LOJ 1045 - Digits of Factorial
---
Tags : Logarithms, Base Conversion, Factorials, Memoization

We will be given the value of __N__, and the basis of the _number system_, __base__. We need to find out the number of digit(s) of the factorial of an integer  (__N!__) in that __base__.

### Helpful Resources
* [Logarithm - Wikipedia](https://en.wikipedia.org/wiki/Logarithm "WikiPedia")
* [Memoization (1D, 2D and 3D) - Geeks for Geeks](https://www.geeksforgeeks.org/memoization-1d-2d-and-3d/ "Geeks for Geeks")

## Solution

To solve this problem we can take help from logarithm formula and rules.

The value of __N__ is given in __base - 10__ number system.
Let's observe what we get when we put __base - 10__ numbers in __log<sub>10</sub>(X)__ :


|Number|log<sub>10</sub>(Number)|⌊log<sub>10</sub>(Number)⌋|Digits|
|:--|:--|:--|:--|
|{0, ..., 9}|0.{something}|0|1|
|{10, ..., 99}|1.{something}|1|2|
|{100, ..., 999}|2.{something}|2|3|
|...|...|...|...|
|X|(Digits(X) - 1).{something}|Digits(X) - 1|__⌊log<sub>10</sub>(X)⌋ + 1__|

But we need to determine the number of digits for __N!__. So, __⌊log<sub>10</sub>(N!)⌋ + 1__ will help us for __base - 10__.

For __⌊log<sub>10</sub>(N!)⌋__, if we recall the formula for __log<sub>10</sub>(X<sub>1</sub> * X<sub>2</sub> * X<sub>3</sub> * ... * X<sub>n</sub>)__,


__log<sub>10</sub>(X<sub>1</sub> * X<sub>2</sub> * X<sub>3</sub> * ... * X<sub>n</sub>) = log<sub>10</sub>(X<sub>1</sub>) + log<sub>10</sub>(X<sub>2</sub>) + log<sub>10</sub>(X<sub>3</sub>) + ... + log<sub>10</sub>(X<sub>n</sub>)__

From the problem, we need to find out the number of digits for __B-based__ numbers instead of __10-based__. Now if we recall the base-conversion formula of logarithms,

__log<sub>b1</sub>(X) = log<sub>b1</sub>(b2) * log<sub>b2</sub>(X)__

=> __log<sub>b2</sub>(X) = (log<sub>b1</sub>(X))/(log<sub>b1</sub>(b2))__

Now we can just do this,

__Digits = ⌊log<sub>b2</sub>(N!)⌋ + 1 = ⌊(log<sub>10</sub>(N!))/(log<sub>10</sub>(b2))⌋ + 1__

To avoid repetition for calculation, we can do __memoization__ in an array for __log<sub>10</sub>(1) + log<sub>10</sub>(2) + ... + log<sub>10</sub>(10<sup>6</sup>)__.

The above implementation is `accepted`.

__Caution__ : Remember to take `digits` as an integer data type that can hold __10<sup>6</sup>__ but avoid floating points.

## Solution in C
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    double memoizedArray[1000001];//Array for Memoization
    memoizedArray[0] = 0; //Don't do manual log for 0, it will throw an error

    //Memoizing the array
    for(int i=1;i<=1000000;i++){
      memoizedArray[i] = memoizedArray[i-1] + log(i);
    }

    int testCase, base;
    long digits,n;

    cin >> testCase;

    for(int i = 1; i<= testCase; i++){
        cin >> n >> base;
        //The formula
        digits = memoizedArray[n]/log(base) + 1;
        cout << "Case " << i << ": " << digits << "\n";
    }

    return 0;
}
```
