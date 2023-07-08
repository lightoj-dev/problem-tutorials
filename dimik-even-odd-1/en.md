# Dimik - Even Odd 1

In this problem, you will be given `T` testcases.Each line of the testcase consists of an integer `n`.We have to determine whether `n` is even or odd.

### Solution 
* If n is divisible by 2
  * its a even number so print 'even'
* if its not divisible by 2 
  * its a odd number so print 'odd'

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
        if (n % 2)
            cout << "odd" << endl;
        else
            cout << "even" << endl;
    }
}
```
