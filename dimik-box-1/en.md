# Dimik - Box 1

In this problem, you will be given `T` testcases. Each line of the testcase consists of an integer `n`. We just have to print `*` in `n` rows and `n` columns.

### Solution
We can find the solution by running two nested loops. We run the outermost loop for each row and for each row we run the innermost loop for each column. The thing to observe here is we print an empty line between consecutive test cases. So there will be no empty lines after last test case.

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
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << "*";
            cout << endl;
        }
       if(k!=t) cout << endl;
    }
}
```
