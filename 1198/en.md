## Summary:

You will be given two arrays of length n let's say *A* and *B* containing n integers. *A<sub>0</sub>,A<sub>1</sub>....A<sub>n-1</sub>* containing the powers of your team and *B<sub>0</sub>,B<sub>1</sub>....B<sub>n-1</sub>* containing the powers of the opposition team. Each *i*-th player of *A* plays one game against a player of opposition team *B*. If *A<sub>i</sub> > B<sub>j</sub>* then your score is 2 and if *A<sub>i</sub> == B<sub>j</sub>* then your score is 1. You have to find the `maximum score` that your team can obtain.


## Solution Idea:
What will happen if we sort these two arrays and compare *A<sub>i</sub>* with *B<sub>j</sub>*? 
 If *A<sub>i</sub> > B<sub>j</sub>* then *A<sub>i</sub>* is also greater than *B<sub>j+1</sub>,B<sub>j+2</sub>....B<sub>n-1</sub>*  and you will win because *B<sub>j</sub> >= B<sub>j+1</sub>...>= B<sub>n-1</sub>*. If *A<sub>i</sub> < B<sub>j</sub>* then you can't win. Finally, It won't work. Consider the case  A = {10,7,3,2,1}  and B = {9,8,7,3,2} :
|  | 0|1 | 2 | 3 | 4 |
|-|-|-|-|-|-|
|**A:**|`10`| 7 | 3 | 2 | 1 |
|**B:**|`9`| 8 |7| 3| 2|

According to this our answer will be 2 as *A<sub>0</sub> > B<sub>0</sub>* and no other comparison gives any score. 
But if we skip *B<sub>1</sub>* and look for next player of *B* for *A<sub>1</sub>* and continue like this we get score 1 from *A<sub>1</sub>-B<sub>2</sub>* , score 1 from *A<sub>2</sub>-B<sub>3</sub>* and score 1 from *A<sub>3</sub>-B<sub>4</sub>*.
||0|1 | 2 | 3 | 4 | 
|-| - | - | -| - | - |
|**A:**|  10 | `7` | 3 | 2 | 1 |
|**B:**| 9| ~~8~~ |`7`| 3| 2|

It will give us a total score 5! That's the idea! If *A<sub>i</sub> <  B<sub>j</sub>* then look for the next opposition player who has power less than or equal to *A<sub>i</sub>* . 
If we continue with *A<sub>i</sub> == B<sub>j</sub>*  this will give us total score 5. But what will happen if we look for the next player of *B*  which is less than *A<sub>i</sub>*
| |0|1 | 2 | 3 | 4 | 
|--| - | - | -| - | - | 
|**A:**|  10 | `7` | 3 | 2 | 1 |
|**B:**| 9| ~~8~~ |~~7~~| `3` | 2|

It will give us total score 6! So, If *A<sub>i</sub> == B<sub>j</sub>* we have two options: either continue with *A<sub>i</sub> == B<sub>j</sub>*  or look for the next player of *B* for *A<sub>i</sub>* and take which option gives maximum score.

## Solution:

We will use `Recursion` to solve this problem.
- First sort A and B in decreasing order.
- Start from i=0 and j=0<br>
**FindMaxScore( A , B , i , j )**
	- If i >= A.size() or j >= B.size() then return 0   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//Base Case
	- If *A<sub>i</sub> > B<sub>j</sub>* then return 2+FindMaxScore( A , B , i+1 , j+1 )
	- If *A<sub>i</sub> < B<sub>j</sub>* then return 0+FindMaxScore( A , B , i , j+1 )
	- If*A<sub>i</sub> == B<sub>j</sub>* then return	max( 1+FindMaxScore(A,B,i+1,j+1) , FindMaxScore(A,B,i,j+1) )

This solution works perfect but causes **TLE**. We will use `dynamic programming` for better performance. Take a 2D array lets say dp of size `nxn`.
where `dp[i][j]` stores the maximum score from *A<sub>i</sub>-B<sub>j</sub>* to *A<sub>n-1</sub>-B<sub>n-1</sub>*. If score is found for *A<sub>i</sub>-B<sub>j</sub>* in `dp[i][j]` return this else continue.

**Code(C++):**
```cpp
#include<bits/stdc++.h>
using namespace std;
int findMaxScore(vector<int>&A, vector<int>&B, vector<vector<int>>&dp, int i, int j)
{
    if(i>=A.size() or j>=B.size())
        return 0;
    if(dp[i][j])
        return dp[i][j];
    if(A[i]>B[j])
        return dp[i][j] = 2+findMaxScore(A,B,dp,i+1,j+1);

    else if(A[i]<B[j])
        return dp[i][j] = findMaxScore(A,B,dp,i,j+1);
    else 
        return dp[i][j] = max(1+findMaxScore(A,B,dp,i+1,j+1),findMaxScore(A,B,dp,i,j+1));
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>A(n),B(n);
        
        for(auto &i:A)
            cin>>i;
        for(auto &i:B)
            cin>>i;

        sort(A.begin(),A.end(),greater<int>());
        sort(B.begin(),B.end(),greater<int>());

        vector<vector<int>>dp(n,vector<int>(n,0));

        cout<<"Case "<<cs++<<": "<<findMaxScore(A,B,dp,0,0)<<endl;
    }  
    return 0;
}
```

**Time Complexity: O(n<sup>2</sup>logn)**
