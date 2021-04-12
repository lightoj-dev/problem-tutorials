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

        /* if the number N is divided by some prime number than
        sum has to be multiped by (1+1) where first 1 is the number of
        that prime number, N is divisible by and second 1 is the plus one
        of the formula. */

        if(n!=1)
            sum*=2;
        printf("Case %lld: %lld\n",++c,sum-1);
    }
    return 0;
}

