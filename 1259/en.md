<h1>Goldbach's Conjecture</h1>
<h2>Summary</h2>
<p>Goldbach's Conjecture is a number theory problem.In this problem you will be given a an integer.
By how many ways, that perticular number can be expressed with the sum of two prime numbers where "first number" is
smaller or equal to "second number".
<h5> "first number + second number = particular number" and "first number <= second number." </h5></p>
<h2>Solution</h2> 
<p>Firstly put those prime numbers in an array by Sieve of Eratosthenes. Secondly take int x=0. After 
that subtract prime number from that perticular number in the 'int' type variable. If the result is a prime number 
and is bigger or equal to the first prime number then the value of x increases by one. 
The loop will break if the second number is bigger than the first number.The value of x is goldbach's conjecture.</p>
<h2>CPP<h2/>
    
```cpp
#include<bits/stdc++.h>
#include<vector>
using namespace std;
bool A[10000001];
vector<int>vec;
int main()
{
    int i,j,n;
    A[0]=true;
    A[1]=true;
    for(i=2;i<10000001;i++)
    {
        if(A[i]==false)
        {
            for(j=i+i;j<10000001;j+=i)
            {
                A[j]=true;
            }
        }
    }
    int k=0;
    for(i=2;i<10000001;i++)
    {
        if(A[i]==false)
        {
            vec.push_back(i);
        }
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        int m,x=0,a=0,b=0;
        scanf("%d",&m);
        while(1)
        {
            b=m-vec[a];
            if(A[b]==false && vec[a]<=b)
                x++;
            else if(vec[a]>b)
                break;
            a++;
        }
        printf("Case %d: %d\n",i,x);
    }
    return 0;
}
```
[Faysal Rahman](https://www.linkedin.com/in/ftowaha/)
