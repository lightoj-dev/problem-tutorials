# LightOJ 1067 - Combinations
## Problem Link: https://lightoj.com/problem/combinations


Given n distinct objects, we have to take k of them. This simply indicates us to find the combination. This is basically a direct combination problem. The formula for calculating the combination is:

![](https://imgur.com/8U0vBUb.png)

If we go through in the conventional way of finding the value of nCr, we will get time limit exceeded verdict. The resultant number could be very large for which we have to mod the number in every step.

First of all we have to precompute the factorials of all number. Then we will get the value of n!, r! and (n-r)!.
Now we can multiply r! and (n-r)! using modular multiplication. It is simple.

**(ab)%m = (a%m * b%m)%m.**

But now is the most important part. We need to handle the division of n! by (r! X (n-r)!) . As like the modular multiplication, **we can’t do this way:**

(a/b)%m =((a%m)/(b%m)) % m

For this, we are now going to be introduced with the new term Modular Multiplicative Inverse.
The modular multiplicative inverse of an integer a modulo m is an integer x such that

![](https://imgur.com/MfdZA5l.png)

That is, it is the multiplicative inverse in the ring of integers modulo m. This is equivalent to

![](https://imgur.com/AB0UAzW.png)

The multiplicative inverse of a modulo m exists if and only if a and m are coprime (i.e., if gcd(a, m) = 1).

Let a=n! and b=r! X (n-r)!<br>
We need to find the modular multiplicative inverse of b with respect to m. Then we can easily perform modular multiplication for a and modular multiplicative inverse of b to find the ultimate output.
We will calculate the modular multiplicative inverse using Fermat’s Little Theorem.
Fermat’s little theorem states that if m is a prime and a is an integer co-prime to m, then a^(p − 1) will be evenly divisible by m. That is

![](https://imgur.com/kokEHYt.png)

or

![](https://imgur.com/LiYg1Hb.png)

In this way we will get the modular multiplicative inverse of b. Let the modular multiplicative inverse of b be B.
Then (a/b)%m will be,

**(a*B)%m = (a%m * B%m)%m**

## **Solution of the problem in C++**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define m 1000003

long long int f[m];

// function to calculate modular mutiplicative inverse of a
long long int bigmod ( long long int a, long long int p)
{
    long long int res = 1;
    long long int x = a;
    while ( p )
    {
        if ( p & 1 )
        {
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }
return res;
}

int main()
{
   long long int i;

   // precompute the factorials of all number

   f[0]=1;
   for(i=1;i<m;i++){
        f[i]=(((i%m)*(f[i-1]%m))%m);
    }

    long long int t,c=0;

    scanf("%lld",&t);
    while(t--)
    {
        long long int n,r,x,y,z,ans,res;
        scanf("%lld %lld",&n,&r);

        //modular multiplication of r! and (n-r)!
        x=((f[n-r]%m)*(f[r]%m))%m;

        //modular multiplicative inverse of x
        y=bigmod(x,m-2);

        //modular multiplication of n! and y
        z=((f[n]%m)*(y%m))%m;

        printf("Case %lld: %lld\n",++c,z);
    }
    return 0;
}