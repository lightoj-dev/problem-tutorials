Dimik - Small to Large

In this problem, you will be given `T` testcases. Each line of the testcase consists of 3 distinct integers denoted by `n1`,`n2` and `n3`. We have to print these 3 integers in ascending order putting empty space between each two consecutive numbers.

### Solution
We can find the solution by either using the `if else` statement to find the minimum, second minimum and consequently the third minimum and then print the three numbers in order or we can store the three numbers in an array and sort them using the `sort()` function and print accordingly.

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
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        cout << "Case " << k << ": " << a[0] << " " << a[1] << " " << a[2] << endl;
    }
}
```
