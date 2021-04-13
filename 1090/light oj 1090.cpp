#include<bits/stdc++.h>
using namespace std;

// calculating the count of x in the number n
int calc_func(int n, int x)
{
    int c = 0;
    while(n>0)
    {
        c+=n/x;
        n = n / x;
    }
    return c;
}
// calculate the count of power of x in the prime factorization of n
int func(int n, int x)
{
    int c = 0;
    while(n % x == 0)
    {
        c++;
        n = n / x;
    }
    return c;
}
int main()
{
    int t,cnt=0;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d,e,f,i,j,k,l,m,o,n,r,p,q,ans,x,y;
        scanf("%d %d %d %d",&n,&r,&p,&q);
        f=n-r;

        /// n!
        i=calc_func(n,2);
        j=calc_func(n,5);

        /// r!
        k=calc_func(r,2);
        l=calc_func(r,5);

        /// (n-r)!
        m=calc_func(f,2);
        o=calc_func(f,5);

        /// p
        x=func(p,2);
        y=func(p,5);

        ans=min(i-k-m+(x*q),j-l-o+(y*q));

        printf("Case %d: %d\n",++cnt,ans);
    }
    return 0;
}
