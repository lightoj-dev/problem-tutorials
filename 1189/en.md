# LOJ - 1189: Sum of Factorials Editorial
---
**What the problem wants :** You will have to express a number as the sum of factorials or decide if its impossible to do so.

**General approach to solution :** The problem can be solved through a brute force method or by trying out all possible combination of factorials . However if we try to calculate the factorial of different numbers individually each time, our solution will be inefficient. That's why in order to make the solution time efficient we will pre-calculate the value of some factorials and store them in an array . Lets take a look at an example to be more clear .

Lets say we want to express `12` as the sum of factorials using a basic brute force approach. We will be seeing if using factorial of different numbers work. But calculating the factorial of each number takes `n!` time. And if we have to do it `k` times (if k is the total number of combination) then our time complexity will become `n! * k`. But, if we pre-calculate all factorials and store them in an array, we can use the array to call the value of factorials instead of calculating them over and over again. The array would look something like the table below:

| index     |   0   |   1   |   2   |   3   |   4   |   5   |   6   |
|:----------|:------|:------|:------|:------|:------|:------|:------|
| factorial |   0!  |   1!  |   2!  |   3!  |  4!   |   5!  |  6!   |
| value     |   1   |   1   |   2   |   6   |  24   |   120 |   720 |

So, instead of calculating `n!` again and again we can simply get the value from `array[n]` .

For the constraints of this problem pre-calculating factorials upto 19 is enough to pass all test cases.

**Resources :**
  1. [Factorial](https://en.wikipedia.org/wiki/Factorial)
  2. [Vector Basics](https://www.geeksforgeeks.org/vector-in-cpp-stl/)
---
### Solution Code
Here is an accepted solution of the problem in _C++_ . An STL _Vector_ is used. If you don't know the use of _Vector_ please see the resources section.
Also be sure to use proper data type as value of factorials can be very large.

**Code :**

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Pre-calculating value of factorials of all numbers from 0 to 19

    long long int factorial[20]={},k=1;
    factorial[0] = 1;

    for(long long int i=1; i<=20; i++)
    {
        factorial[i] = i*k;
        k = factorial[i];
    }

    //start of actual solution
    int testcase;
    cin>>testcase;
    for(int j=1; j<=testcase; j++)
    {
        long long int n;
        cin>>n;

        vector<int>answer;
        for(int i=20; i>=0; i--)
        {
            if(factorial[i]<=n)
            {
                n-=factorial[i];
                answer.push_back(i);
            }

        }

        // Output
        cout<<"Case "<<j<<": ";
        if(n==0)
        {
            for(int i=answer.size()-1; i>0; i--)
            {
                cout<<answer[i]<<"!+";
            }
            cout<<answer[0]<<"!\n";
        }
        else
            cout<<"impossible\n";

    }
    return 0;
}

```
