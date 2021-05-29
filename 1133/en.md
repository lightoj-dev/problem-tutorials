# LOJ 1133 - Array Simulation

This is an another easy problem with lightoj volume.
In this problem you are given an array named a and the size of the array n.
Here you are also given some operations.The operations are:

1. S D -> This operation means D will be added with all the elements of the array.
2. M D -> This operation means all the elements of the array will be multiplied by D.
3. D K -> This operation means all the elements of the array will be divided by K(integer division).
4. P Y Z -> This operation means swap the elements a[Y] and a[Z].
5. R -> This operation means reverses the whole array, i.e [1, 2, 4, 3], becomes [3, 4, 2, 1].

After finishing all the operations you have to print the elements of the array.
Since here the maximum array size is 100 and operations size is 101 so we can easily implement using bruteforce.
Suppose you are given an array of size 5 like [ 1,2,3,4,5 ]
And there are an operation S 1.So after finising this operation the array looks like [2,3,4,5,6 ]
Using this way we iterate all the operations and traverse the whole array again and again.

Total Complexity: O(N * Q).
Here N is the size of the array and Q is the size of operations.

If you are still stuck with this problem, check the codes below:

### C++ 

```c++
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long  ts,cs=1;
    scanf("%ld",&ts);
    while(ts--)
    {
        long a,b,k,i,ar[105]= {0},ar1[105]= {0},y,z;
        char ch[10]= {0};
        scanf("%ld",&a);
        scanf("%ld",&b);
        for(i=0; i<a; i++)
        {
            scanf("%ld",&ar[i]);
        }
        long d,i1;
        for(i=1; i<=b; i++)
        {
            scanf("%s",ch);
            if(strcmp(ch,"S")==0)
            {
                cin>>d;
                for(i1=0; i1<a; i1++)
                {
                    ar[i1]=ar[i1]+d;
                }
            }
            if(strcmp(ch,"M")==0)
            {
                cin>>d;
                for(i1=0; i1<a; i1++)
                {
                    ar[i1]=ar[i1]*d;
                }
            }
            if(strcmp(ch,"D")==0)
            {
                cin>>d;
                for(i1=0; i1<a; i1++)
                {
                    ar[i1]=ar[i1]/d;
                }
            }
            if(strcmp(ch,"R")==0)
            {
                k=0;
                for(i1=a-1; i1>=0; i1--)
                {
                    ar1[k++]=ar[i1];
                }
                for(i1=0; i1<a; i1++)
                {
                    ar[i1]=ar1[i1];
                }
            }
            if(strcmp(ch,"P")==0)
            {
                cin>>y>>z;
                swap(ar[y],ar[z]);
            }
        }
        printf("Case %ld:\n",cs++);
        for(i=0; i<a; i++)
        {
            if(i==0)
                cout<<ar[i];
            else
                cout<<" "<<ar[i];
        }
        cout<<endl;
    }
	return 0;
}
```
