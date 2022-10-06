# LOJ 1389 - Scarecrow

In this problem you will be given __T__ test cases. Each case starts with a line containing an integer __N (0 < __N__ < 100)__. The next line contains __N__ characters that describe the __1 x N__ rectangular field. A dot(__.__) indicates a crop-growing spot and a hash(__#__) indicates an infertile region. For each case, you have to print the case number and the minimum number of scarecrows that need to be used.

### Observation and Solution:

This is a straight forward greedy problem. A scarecrow, when placed on a spot, covers the cell to its immediate left and right along with the cell it is on. So basically it covers three consecutive cells. Hence the efficient approach would be traversing the field from either left or right(the code given below traverses from left) and once we find an uncovered crop-growing cell(a dot), we will need a scarecrow to cover that cell and the next two cells(if exist) will be automatically covered(no matter what type of cells they are, dots or hashes) by that scarecrow. So we can skip iteration for the next two cells of a covered crop-growing cell(a dot). We will count the number of scarecrows needed throughout this process and after traversing the whole field, the number of scarecrows needed will be our desired result.

### Code:
### C++
-----
```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    for(int cs = 1; cs <= t; cs++) {
        int n, cnt;
        string field;
        cin>>n;
        cin>>field;
        cnt = 0;

        for(int i = 0; i < n; i++) {
            if(field[i] == '.') {
                i += 2;
                cnt++;
            }
        }

        cout<<"Case "<<cs<<": "<<cnt<<"\n";
    }

    return 0;
}
```

 Happy coding! :3
