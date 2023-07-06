# LOJ 1509 - ICPC Standing

In this problem, you will be given `T` testcases. The first line of each test case contains three integers `P` ,`S` and `R` where `P` denotes the number of problems in the problem set, `S` denotes the number of solved problems by the current team and `R` denotes the rank of the current team.
Now, in the problems statement it was asked if there was a chance for the current team to become champion after the end of the contest.


### Approach:
This is a very simple adhoc problem.The current team will only not be able to become the champion of the contest if they have solved all the problems that are in the problem statement and still couldn't achieve the first position.Other than this there is always a chance for the current team to become champion after the end of the contest.

If you are still stuck with this problem, check the code below:

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
        int p, s, r;
        cin >> p >> s >> r;
        cout << "Case " << k << ": ";
        if (p == s and r != 1)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}
```
