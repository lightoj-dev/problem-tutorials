Chess board knights only travel in L shaped squares. 

In this  problem there are 3 cases mainly considerable.

- **Case 1:**  If any of  the rows or columns is 1 then there is no L shaped formed. So answer is max of row and column.[See the pic](https://ibb.co/zF8114s) for better understanding.

- **Case 2:**  If rows and columns are greater then 2 then just half the total of squares is the answer.

- **Case 3:**(most important case) If either of the row or column is 2 then we just divide the total squares by 8 where 1st 4 blocks can be placed by knights and other 4 blocks are forbidden. [See the pic](https://ibb.co/sJPy0Vr) for better understanding.
The remaining blocks(if any) if less then or equals 4 then remaining  blocks are added to the answer and if greater then we add 4 to the answer.

```
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
```


 Happy coding.
