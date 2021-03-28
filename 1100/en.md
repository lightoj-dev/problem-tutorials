# LOJ 1100 - Again Array Queries

In this problem, you will be given `T` testcases. The first line of each test case contains two integers `n`  and `q` where `n` denotes the number of elements of the array and `q` denotes the number of queries.
The second line consists of elements which form the array.The next q lines consists of two integers i and j which denotes the range of elements of the array from ith index to jth index.

Now, in the problems statement it was told for each and every query given in the input we need to compute the minimal difference between two integers in the range of ith to jth index.


### Approach:
In order to solve this problem we take the following approach:

For each and every query we take the elements of the array from ith index to jth index into a vector.Then, we sort the vector and later compute
the minimal difference by taking the difference of every two consecutive elements of the vector.If you are wondering , why we need to sort the vector,the answer to that is we can find the minimal
difference more efficiently and in lesser time that way because the values of two consecutive elements in a sorted vector are close to each other.The closer the value of two consecutive elements is,the lesser is the difference.
That's why the vector is to be sorted.
Note that,even though the constraint of n is quite high which is `2<= n <=10^5` ,the  constraint of the array elements lies in [1,1000].So when the difference of indices of a query that is i and j
is greater than 1000,we don't need to go through this process rather we output 0 as the final answer.The reason being in a range of indices of having difference greater than 1000,there must be atleast
one value which is repetitive and the difference of repetitive values is 0 which is the minimal non-negative integer possible.Hence,that is the final answer.

If you are still stuck with this problem, check the code below:

### C++
```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        int n,q;
        cin>>n>>q;
        int a[n+2];
        for(int i=0; i<n; i++)
            cin>>a[i];
        cout<<"Case "<<k<<":"<<endl;
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            if(y-x>1000)
                cout<<0<<endl;
            else
            {
                vector<int>v;
                for(int i=x; i<=y; i++ )
                {
                    v.push_back(a[i]);
                }
                sort(v.begin(),v.end());
                int ans=1000;
                for(int i=1; i<v.size(); i++)
                {
                    ans=min(ans,v[i]-v[i-1]);
                }
                cout<<ans<<endl;
            }
        }
    }
}
```
