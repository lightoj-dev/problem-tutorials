# LOJ 1389 - Scarecrow

### Summary:

First, you will be given an integer __T (1 ≤ T ≤ 100)__ denoting the number of test cases. Each case will start with a line containing an integer __n (1 ≤ n ≤ 10)__, where __n__ denotes the total number of reports of the size of Pinocchio's nose in a certain day. The next line contains __n__ space separated integers: __a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>__ denoting the sizes of his nose in that day. All the values of __a<sub>i</sub> (1 ≤ i ≤ n)__ will be between 2 and 50.

### Idea:

 We have to find the minimum number of lies Pinocchio has told. When he tells a lie, his nose grows at least 1 cm and at most 5 cm. So assuming his nose grows 5 cm for most of the lies he tells will minimize our answer. For example, if his nose grows 13 cm in a certain period of time, then the minimum number of lies will be 3 (we have to work with the ceiling values here).

 As it is assumed that he hasn't told any truth, the given values of __a<sub>i</sub> (1 ≤ i ≤ n)__ will be in non-decreasing order. So we don't have to sort the values. We will use a counter variable to store the answer. We will run a loop __n__ times and work with __a<sub>i</sub>__ and __a<sub>i-1</sub> (1 ≤ i ≤ n)__ in each iteration. Every time we will add the ceiling value of __(a<sub>i</sub> - a<sub>i-1</sub>)/5__ with the counter (Note: In first iteration we have to work with __a<sub>1</sub>__ and the initial size of Pinocchio's nose. So we can assume that __a<sub>0</sub>__ = 2). Finally, we have to print the value of the counter variable. The space and time complexity both will be __O(n)__ for each of the __T__ tast cases.

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

    for(int cs=1; cs<=t; cs++) {
        int n, cnt;
        cin>>n;
        vector<int> vec = {2};    /// initialing the vector with the initial size of Pinocchio's nose
        cnt = 0;

        for(int i=1; i<=n; i++) {
            int x;
            cin>>x;
            vec.push_back(x);
        }

        for(int i=1; i<vec.size(); i++) {
            cnt += (vec[i]-vec[i-1]+4)/5;    /// taking the ceiling value
        }

        cout<<"Case "<<cs<<": "<<cnt<<endl;
    }

    return 0;
}
```

 Happy coding! :3
