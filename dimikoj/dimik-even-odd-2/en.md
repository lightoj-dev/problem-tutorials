# Dimik - Even Odd 2

In this problem, you will be given `T` testcases.Each line of the testcase consist of an integer `n` which can be a number consisting of maximum 100 digits.We have to determine whether `n` is odd or even.

## Hint: You just need to handle last bit 

### Solution 
* for each test case take the number as a string 
* Check the last character of the string 
* make it integer 
* If its divisible by 2
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
        string s;
        cin >> s;
        string tmp = "";
        tmp += s[s.size() - 1];
        int val = stoi(tmp);
        if (val % 2)
            cout << "odd" << endl;
        else
            cout << "even" << endl;
    }
}
```
