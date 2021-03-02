
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 1010105
using namespace std;
#include <chrono>
using namespace std::chrono;
int prime[maxn];
int v[maxn];
int cnt;
void db()
{
	memset(v,0,sizeof(v));
	cnt=0;
	int i,j;
	for(i=2;i<maxn;i++)
	{
		if(!v[i])
		{
			prime[cnt++]=i;
			for(j=i*2;j<maxn;j+=i)
				v[j]=1;
		}
	}
}
int main()
{	
	//auto start = high_resolution_clock::now();
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	db();
	int t,i,j,a;
	long long n;
	int cas=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		long long int ans=1;
		for(i=0;i<cnt&&prime[i]*prime[i]<=n;i++)
		{
			if(n%prime[i]==0)
			{
				int ccnt=0;
				while(n%prime[i]==0)
				{
					ccnt++;
					n/=prime[i];
				}
				ans=ans*(ccnt+1);
			}
		}
		if(n>1)
			ans*=2;
		printf("Case %d: ",++cas);
		printf("%lld\n",ans-1); 
	}
	//auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(stop - start); 
    //printf("Time taken by code: %d seconds\n",(int)(duration.count()/1000000));
	return 0;
}