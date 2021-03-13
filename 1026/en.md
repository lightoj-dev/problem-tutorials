# LOJ 1026 - Critical Links 

Suppose there is a interconnected network between several server or nodes,In these network some nodes are said critical link which generates two disjoint(there is no other path) sub-networks such that any two servers of a sub-network are interconnected

## Solution

It is a very basic problem in Bridge(graph) concept ...Actually we need to find how many bridges exists in this graph.Taking input of graph is interesting.First we construct graph and run DFS tree to find back edge and forward edge using discovery time and low time(means there another path exists). And finally make pair of vertices and print it.

Bridge concept: A bridge is defined as an edge which when romoved makes graphs disconnected. More precisely it increases number of connected components. Why we use DFS? The idea behind this is that it will create the simple structure of the graph and so we can easily determine back edge/forward edge. Back edge/forward edge is nothing but it says a node has multiple path to reach so we can confirm there is a cycle. A cyclic path can't be a bridge. Try to figure out. 

```cpp

#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;
vi g[10005];
int visit[10005],low[10005],in[10005];
vector<pair<int,int> > bridge;
int cnt,timer;
void dfs1(int s,int p)
{
    visit[s]=1;
    low[s]=in[s]=++timer;
    for(int i=0;i<g[s].size();i++)
    {
        if(g[s][i]==p)
            continue;
        else if(visit[g[s][i]])
            low[s]=min(in[g[s][i]],low[s]);
        else
        {
            dfs1(g[s][i],s);
            if(low[g[s][i]]>in[s])
            {
                cnt++;
                if(g[s][i]>s)
                bridge.pb(make_pair(s,g[s][i]));
                else
                bridge.pb(make_pair(g[s][i],s));
            }
            low[s]=min(low[g[s][i]],low[s]);
        }
    }

}
int main()
{
    int t,n,e,u,v,cs=0;
    char a,b,c;
    cin>>t;
    while(t--)
    {
        cnt=0,timer=0;
        cin>>n;
       for(int i=0;i<n;i++)
       {
           g[i].clear();
           visit[i]=0;
       }
       bridge.clear();
       for(int i=0;i<n;i++)
       {
           cin>>u;

           scanf("%c%c%d%c",&c,&c,&e,&c);
           while(e--)
           {
               cin>>v;
               g[u].pb(v);
               g[v].pb(u);
           }
       }
       for(int i=0;i<n;i++)
       {
           if(!visit[i])
           {
               dfs1(i,-1);
           }
       }
      // dfs1(0,-1);
       cout<<"Case "<<++cs<<":"<<endl;
       cout<<cnt<<" critical links"<<endl;
        sort(bridge.begin(), bridge.end());
       for(int i = 0; i <bridge.size(); i++)
       {
         cout << bridge[i].first << " - " << bridge[i].second << endl;
    }

    }


    return 0; 

    
}

```
