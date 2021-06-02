# Loj 1095 - Arrange the Numbers


_Calculate the number of arrangements of first `N` natural numbers, where in first `M` positions; exactly `K` numbers are in their initial position._

---


### Solution

This is a Number Theory (Counting and Derangement) problem. In order to solve this problem you must have some ideas about this topics. 

If you aren't already familiar with How to calculate Binomial Coefficients and Derangement, have a walk through these links:

- [CP-Algorithm: Binomial Coefficients](https://cp-algorithms.com/combinatorics/binomial-coefficients.html)
- [Brilliant: Derangements](https://brilliant.org/wiki/derangements/)

Let's assume you got a proper knowledge on Binomial Coefficients and Derangements with efficient implementation.

As we have to calculate the number of ways to arrange the numbers so that exactly `K` numbers are in their initial position in first `M` positions, so let's divide this in some parts. 

First let's consider, for the first `M` position, we have `(1..M)` or `M` possible numbers to choose. So we can choose `k` fixed places from `m` possible options in `mCk` ways.

Now as we have K fixed places and they will remain constant in all arrangements, we must make sure there is no other elements in the their initial position among first `M` numbers. So for the remaining positions we have two cases: the position need derangement or we can put any number in that position. 

If we have a close look, we can see there are `M-K` positions, where derangement is must and rest, `M..N` positions doesn't matter what we put.

*Let's observe this part:*

Now let's think how many ways we can put a number in remaining `M-k` positions? we can take any number from `M-K-1` position or remaining `N-M` positions. 

- We take the number from `M-K-1` positions we have two cases:   
Let's assume `y` is the position in within `M-K-1` from where we are taking number and `x` is the position where we are putting the number. There can be two option:

   - a) We put the number from `y` in place `x`. And you put the number that was in `x` into `y`. So `x` and `y` are already changed now.
   
   - b) We put the number from `y` in `X`, but we don't want to put `x`'s number in `y`. That means, it's forbidden for `x`'s number to be in `y`, i.e. `y` still needs to be deranged. 
-  We take number from `N-M` places so we still have two cases:   
Let's assume `y` is the position in within `N-M` from where we are taking number and `x` is the position where we are putting the number. There can be two option:
   - a) We put `y`'s number in `x` and `x`'s number in `y`. So, now you have `M-K-1` numbers to derange and `N-M-1` numbers free.
   - b)  We put `y`'s number in `x` but don't want to put `x`'s number in `y`. So, we still need to derange `y`. i.e. the number of places to still derange is `M-K-1+1` = `M-K`. But you did use up one of the free numbers from `y`. 

So using derangement observations we can simply come to a final statement:  for each elements from `N-M` choose `X` elements and derange the rest,`N-X-K` of the elements. 

_**Note**: we used dp tables to store the values to instead of calculating the values every time._


#### Code

### C++

```Cpp
#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e3+7;
long long mod = 1000000007;
long long dpArrange[nmax][nmax];
long long dpDerange[nmax];

long long nCr(int n,int r){
    if(r==1) return n;
    if(r==0 || r==n) return 1;

    long long &ret = dpArrange[n][r];

    if(ret!=-1) return ret;

    ret = ((nCr(n-1,r-1)%mod) + (nCr(n-1,r)%mod))%mod;

    return ret;
}

long long Derange(int n){
    if(n==1) return 0;
    if(n==2 || n==0) return 1;

    long long &ret = dpDerange[n];

    if(ret!=-1) return ret;

    ret = ((n-1)%mod * (Derange(n-1)%mod+Derange(n-2)%mod)%mod)%mod;

    return ret;
}
 
 
int main(){
   
    int tc;
    cin>>tc;

    memset(dpArrange,-1,sizeof dpArrange);
    memset(dpDerange,-1,sizeof dpDerange);
 
    for(int t=1; t<=tc; ++t){
        int n,m,k;
        cin>>n>>m>>k;

        long long fixed = nCr(m,k); /** Choose any k from first m elements **/
        long long derPos = 0;

        for(long long i=0;i<=n-m;i++)
            derPos = (derPos%mod + (nCr(n-m,i)%mod * Derange(n-i-k)%mod)%mod)%mod;    /** Choose i from n-m elements and Derange the rest i.e n-i-k elements **/

        cout<<"Case "<<t<<": "<<((fixed*derPos)%mod)<<endl; 

 
    }

    return 0;
}
```