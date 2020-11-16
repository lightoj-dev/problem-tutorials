### LOJ-1010 - Knights in Chessboard

In this problem you are given "T" test cases where "n" and "m" are rows and columns respectively.For each test cases you have to print the total empty spaces for Two knights to place without attacking each other.

Knights in the board travel in "L" shape.In this  problem there are 3 cases mainly considerable.

- **Case 1:**  If any of  the rows or columns is 1 then there is no "L" shaped formed. So answer is max of row and column.
![Knight-in-1-row](https://user-images.githubusercontent.com/58706003/99261396-df0e2500-2846-11eb-8b94-a99262f2a46a.jpg)

- **Case 2:**  If rows and columns are greater then 2 then just half the total of squares is the answer.

- **Case 3:**(most important case) If either of the row or column is 2 then we just divide the total squares by 8 where 1st 4 blocks can be placed by knights and other 4 blocks are forbidden.The remaining blocks(if any) if less then or equals 4 then remaining  blocks are added to the answer and if greater then we add 4 to the answer.
![Knight-in-2-row](https://user-images.githubusercontent.com/58706003/99261602-21cffd00-2847-11eb-9f34-43bde191856e.jpg)


Code:
### C++
-----
```c++
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ll long long 
const int N=1e5+5;
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;cin>>t;
    int i=1;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        if(m==1 or n==1)
        {
            cout<<"Case "<<i<<": "<<max(n,m)<<endl;
        }
        else if(n==2 or m==2)
        {
            cout<<"Case "<<i<<": "<<((m*n)/8)*4 + (((m*n)%8)>=4?4:(m*n)%8)<<endl;
        }
        else
        {
            cout<<"Case "<<i<<": "<<(n*m+1)/2<<endl;
        }
        i++;
    }
	return 0;
}

```


 Happy coding.
