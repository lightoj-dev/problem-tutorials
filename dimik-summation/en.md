# Dimik - Summation

In this problem, you will be given `T` testcases. Each line of the testcase consists of a 5 digit integer `n`. We just have to print the summation of leftmost and rightmost digit of an integer `n`.

### Solution
We can find the solution by dividing the integer `n` by 10000 to get the leftmost digit and finding the remainder of `n` being divided by 10, we get the rightmost digit. Once we obtain both the digits, we can add them and print them in the format `Sum = summation of both digits`.

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
        int sum = 0;
        sum += n / 10000;
        sum += n % 10;
        cout << "Sum = " << sum << endl;
    }
}
```
