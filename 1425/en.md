# LOJ 1425- The Monkey and the Oiled Bamboo

Suppose you have a bamboo and you have to climb up using it.But here you can't skip any step when you climb up.
You must climb up step by step. Here you are also given an energy k.It means you climb up at most k steps.
When you jump and goto k steps then k will be decrease by one. So we can easily find that we can at most k-1 height jump.
Again if you jump k-1 heights, then you can jump at most k-2 heights.
Here you are given the height of every steps of the bamboo. Now you have to find k that which you cross all the steps using this k.
You have to find k as minimum as possible. 

Solution approach:

We can use difference array to solve this problem. At first we calculate all the difference between two neighbouring index.
Then sort the difference array and store the maximum difference into a variable.Ex: int a=diff[lastPostion-1] -1;
After all iterate the whole array and check by this value if it equal to the next difference then decrease the value of a, otherwise break the loop.
If the value of each of the difference arrays is difference 1, then in the end the last value of the difference array is the answer, otherwise we can get the answer by adding 1 to the last value.
 


If you are still stuck with this problem, check the codes below:

### C++ 

```c++
#include<bits/stdc++.h>
#define fr(i1,m) for(int i1=0;i1<m;i1++)
using namespace std;
int main()
{
    long n,m;
    cin>>n;
    fr(i1,n)
    {
        long a[100000]= {0},tt=0,i,j,c=0,x,k,l,p=1,b[100000]= {0};
        cin>>m;
        fr(i,m)
        cin>>a[i];
        b[0]=a[0];
        for(i=1; i<m; i++)
        {
            b[p++]=a[i]-a[i-1];
        }
        sort(b,b+p);
        x=b[p-1]-1;
        for(i=p-2; i>=0; i--)
        {
            if(x==b[i])
                x--;
            else if(x<b[i])
            {
                tt=1;
                break;
            }
        }
        if(tt==1)
        {
            printf("Case %ld: %ld\n",i1+1,b[p-1]+1);
        }
        else
            printf("Case %ld: %ld\n",i1+1,b[p-1]);

    }
    return 0;
}
```
