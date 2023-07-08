# Dimik - Factorial

In this problem, you will be given `T` testcases.Each line of the testcase consist of an integer `n`.We have to determine the factorial value of `n`

### Solution
Factorial of any value n denotes finding the product of all the values starting from 1 upto n.
In other words `Factorial[n]=1*2*3*4...*(n-2)*(n-1)*n`.
So we can make an efficient solution, by preprocessing all the factorials for different possible values of n and while going through the test cases,we can just print out the factorial of `n`.

### C++
```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int fact[16];
    fact[0] = 1;
    for (int i = 1; i <= 15; i++)
    {
        fact[i] = i * fact[i - 1];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << fact[n] << endl;
    }
}
```
