# Dimik - Summation

In this problem, you will be given `T` testcases. Each line of the testcase consists of a 5 digit integer `n`. We just have to print the summation of leftmost and rightmost digit of an integer `n`.

### Solution
We can find the solution by square rooting the value of `n` using `sqrt` function and multiply against itself through the use of `floor` function. Because the value returned by `sqrt` function is `double` and to compare with the `integer` value of `n`, the datatype `double` is converted to `int` using `floor` function.

### C++
```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int n;
        cin >> n;
        if (floor(sqrt(n)) * floor(sqrt(n)) == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
```
