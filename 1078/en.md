# LOJ 1078 - Integer Divisibility

## Hint

1. If your data type is even long long int (in C++ it is the highest data type), it can not hold the sequence and because of overflow as there may be 10^6 digit ans you will get WA.
2. If your data type is string then you will get “time limit exceeded” as you need to process loop 10^6*10^6=10^12 times. To avoid these problems we need to follow a trick here.

 So simply check divisibility digit by digit such as if input is 3 1 then number is = 111 . So at first check 1 then 11 and last 111. That remainder r can be checked by this rule (if n is 3 and m is 1) `r=(r*10+m)%n`<br>
 Continue this until reminder becomes 0. Also note down how may times this operation need.

 **Prerequisites : Modular Arithmetic**

## Code
### C++

```cpp

#include <bits/stdc++.h>
using namespace std;

void _main_main()
{
    int percent , digit , rem = 0 ;
    cin >> percent >> digit ;

    int cnt = 0 ;
    while (1)
    {
        rem = (rem *10 + digit)%percent ;
        cnt++ ;
        if (rem == 0) break ;
    }
    cout << cnt << "\n" ;
}

int main ()
{
    int testCase = 1 ; cin >> testCase ;
    for (int i = 0; i < testCase; i++){
        cout << "Case " << i+1 << ": " ;
        _main_main() ;
    }
}

```

Happy Coding!

Written by: [Moontasir Mahmood](https://www.linkedin.com/in/munmud/)