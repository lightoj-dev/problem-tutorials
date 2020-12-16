# LOJ 1286 - Space Shuttle Experiments 

_Keywords: Flows, Min-Cut_

Consider vertices for each experiments and instruments. Also consider two extra vertices, source and sink. Do the following:

* for each experiment i, add an edge from source to the corresponding node with the capacity p(i) i.e. the profit if that experiment is conducted.
* for each instrument i, add an edge from the corresponding node to sink with capacity c(i) i.e. the cost if that instrument shall be used.
* add an edge from an experiment to each of the instrument the experiment requires with capacity INFINITY.

Compute the minimum cut of this graph. The result will be summation of all e(i) minus the min cut value.

__How?__

Let's consider the minimum cut. Since the edge from an experiment to an instrument has capacity INF, we can be assured that the cut won't consist of such edges. So, there can be two types of edges in the cut:

1. source to experiment: we shall consider that we are not doing this experiment, thus negating the profit we added in the resulting equation (the sum of e(i) that we did).
2. instrument to sink: if this edge appears in the cut, that means there was an edge from source to some experiemnt (which depends on this instrument) that was not in the cut. Thus, we have to add the cost of this instrument since we are conducting an experiment requiring this. So, we negate this cost from the sum of e(i) i.e. the profits.

Since we are negating positive edge capacities and are in fact trying to maximize the result, it's only sensible that we'll be looking for the minimum cut.

__Concerns to be concerned about:__
* Instead of INF, if we chose some random small values for the capacities of the edges from experiments to instruments, what'd happen? What does that mean?

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 2000000001

/***** Maxflow routines start *****/
const int MAX_E=40501;	// 60003
const int MAX_V=251;	// 5003
int ver[MAX_E],cap[MAX_E],nx[MAX_E],last[MAX_V],ds[MAX_V],st[MAX_V],now[MAX_V],edge_count,S,T;

inline void reset()
{
	memset(nx,-1,sizeof(nx));
	memset(last,-1,sizeof(last));
	edge_count=0;
}
inline void addedge(const int v,const int w,const int capacity,const int reverse_capacity)
{
	ver[edge_count]=w; cap[edge_count]=capacity; nx[edge_count]=last[v]; last[v]=edge_count++;
	ver[edge_count]=v; cap[edge_count]=reverse_capacity; nx[edge_count]=last[w]; last[w]=edge_count++;
}
inline bool bfs()
{
	memset(ds,-1,sizeof(ds));
	int a,b;
	a=b=0;
	st[0]=T;
	ds[T]=0;
	while (a<=b)
	{
		int v=st[a++];
		for (int w=last[v];w>=0;w=nx[w])
		{
			if (cap[w^1]>0 && ds[ver[w]]==-1)
			{
				st[++b]=ver[w];
				ds[ver[w]]=ds[v]+1;
			}
		}
	}
	return ds[S]>=0;
}
int dfs(int v,int cur)
{
	if (v==T) return cur;
	for (int &w=now[v];w>=0;w=nx[w])
	{
		if (cap[w]>0 && ds[ver[w]]==ds[v]-1)
		{
			int d=dfs(ver[w],min(cur,cap[w]));
			if (d)
			{
				cap[w]-=d;
				cap[w^1]+=d;
				return d;
			}
		}
	}
	return 0;
}
inline long long flow()
{
	long long res=0;
	while (bfs())
	{
		for (int i=0;i<MAX_V;i++) now[i]=last[i];
		while (1)
		{
			int tf=dfs(S,INF);
			res+=tf;
			if (!tf) break;
		}
	}
	return res;
}
/***** Maxflow routines end *****/

const int N = 109;
int p[N], c[N];

int main() {
	int t, tc=0;
	scanf("%d", &t);

	while(t--) {
		int n, m;
		scanf("%d %d", &m, &n);
		reset();
		S = 0, T = n+m+1;
		for(int i=1; i<=m; ++i) {
			scanf("%d", p+i);
			addedge(S, i, p[i], 0);
		}
		for(int i=1; i<=n; ++i) {
			scanf("%d", c+i);
			addedge(i+m, T, c[i], 0);
		}
		ll tot = 0;
		for(int i=1; i<=m; ++i) {
			tot += p[i];
			int q;
			scanf("%d", &q);
			while(q--) {
				int v;
				scanf("%d", &v);
				addedge(i, v+m, INF, 0);
			}
		}
		ll temp = flow();
		ll res = tot - temp;
		printf("Case %d: %lld\n", ++tc, res);
	}

	return 0;
}
```

---
_reborn++_ <br/>
_Dec 09 2020_
