# Problem Title : Trailing Zeroes (I)
## Problem link- https://lightoj.com/problem/trailing-zeroes-i


First of all, let us consider the fact: how we convert a 10 base number to a 2 base number. Simple it is. We have to divide the number with 2 until we get the quotient = 0. Now, we will try to convert the number 156 from base 10 to base 2.


![Bin_Convert](https://user-images.githubusercontent.com/40003419/170428428-e61cd9dc-d0ae-4941-a6fe-34e5ab6d4caa.jpeg)

                               
The binary representation of the number (156)<sub>10</sub> will be (10011100)<sub>2</sub>. The first remainder actually represents the last digit. We need to find the number of bases when converted from base 10, there will be at least one trailing zero. For the the last digit has to be zero. We don't need to see the rest. The last digit becomes 0 only if the number N is divided by the base.

In the image, we can see that we get 0 as remainder only when the number N is divided by the base. Only then we can get the first remainder as 0. So, we need to find out the number of divisors of N. N is always divided by 1. But we have to ignore it as the question demands us to find base from 2 to infinity. So, we have to reduce our answer by 1.

In order to solve the problem, we need to find the number of divisors and then reduce it by 1.

We know that if the prime factorization of a number N is p<sub>1</sub><sup>e1</sup>⋅p<sub>2</sub><sup>e2</sup>⋯p<sub>k</sub><sup>ek</sup>, where p<sub>i</sub> are distinct prime numbers, then the number of divisors is:
d(n)=(e1+1)*(e2+1)⋯(ek+1)

So, the answer will be d(n)-1.


# Solution of the problem in C++ 
```cpp
#include <bits/stdc++.h>
using namespace std;
#define m 1000010

long long int primes[m], cnt, siv[m];

void sieve()
{
    long long int i, j;
    for (i=3; i<m; i+=2)
        if(!siv[i])
            for (j=i*i; j<m; j+=i+i)
                siv[j]=1;
    primes[cnt++]=2;
    for (i=3; i<m; i+=2)
        if(!siv[i]) primes[cnt++]=i;
    return;
}



int main()
{
    sieve();
    long long int t,c=0;
    scanf("%lld",&t);
    while(t--)
    {
        long long int n,sum=1,s,k,i;
        scanf("%lld",&n);

        // finding the number of divisors of N
        for(i=0;i<m && primes[i]*primes[i]<=n;i++)
        {
            if(n%primes[i]==0)
            {
                k=0;
                while(n%primes[i]==0)
                {
                    n/=primes[i];
                    k++;
                    if(n==0 || n==1)
                        break;
                }
                sum*=k+1;
            }

        }

        /* If the number N is divided by a prime number than the
        sum has to be multiped by (1+1) where first 1 is the count of
        that prime number, N is divisible by and second 1 is the plus one
        of the formula. */

        if(n!=1)
            sum*=2;
        printf("Case %lld: %lld\n",++c,sum-1);
    }
    return 0;
}

```

