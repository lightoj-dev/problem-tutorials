# LOJ 1174 - Commandos

### Problem summary:

Each test case will have a graph consisting of __N__ buildings (nodes) and __R__ roads (edges). Each road has one unit edge cost. The task is to determine the minimum time needed to place a bomb in each building given that the commandos will start their mission from a specific building __s__ and reunite at a specific building __d__ after finishing their mission. You have unlimited supply of commandos each having unlimited number of bombs.

### Observations and Solution:

As the graph is not weighted, we can solve this problem using BFS. But how to minimize the time? It is easy to observe that using one commando to place bombs in all the buildings is not a good idea. Also we have unlimited supply of commando troops. So we can take __N__ commandos and assign each commando for only one building and in this way we can get the optimal result. For example: A commando's task is to place a bomb in the building __x__. He will start from __s__ and will go to __x__ using the shortest path between __s__ and __x__. After placing the bomb he will go to __d__ using the shortest path between __x__ and __d__. In this way all the commandos will take minimum time possible to finish their job. Among all these times, the maximum one will be the minimum time to complete the mission.

To implement the solution, we need to run two BFS. First BFS will start from __s__ and calculate the costs of the shortest paths of all the buildings from __s__. Another BFS will start from __d__ and find the costs of the shortest paths of all the buildings from __d__. The time needed to place bomb in a building will be the sum of its distances from __s__ and __d__. For all the buildings __i (0 ≤ i < N)__ we will take the maximum of those times:

`answer` = `max(answer, distance_from_s[i] + distance_from_d[i])`.

### Helpful resources:

* [BFS tutorial - Shafaet's blog](http://www.shafaetsplanet.com/?p=604)
* [BFS visulization - William Fiset](https://www.youtube.com/watch?v=oDqjPvD54Ss)

### Code:
#### C++
-----
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;
vector<int> dis_from_s, dis_from_d;
vector<vector<int> > graph;

void bfs(int node, vector<int>& dis)
{
    queue<int> q;
    vis[node] = true;
    q.push(node);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(auto v: graph[u])
        {
            if(!vis[v])
            {
                vis[v] = true;
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    for(int cs=1; cs<=t; cs++)
    {
        int n, r, s, d, ans = 0;
        cin>>n>>r;
        vis.assign(n, false);
        dis_from_s.assign(n, 0);
        dis_from_d.assign(n, 0);
        graph.assign(n, vector<int>());

        for(int i=0; i<r; i++)
        {
            int u, v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cin>>s>>d;
        bfs(s, dis_from_s);
        fill(vis.begin(), vis.end(), false);
        bfs(d, dis_from_d);

        for(int i=0; i<n; i++)
            ans = max(ans, dis_from_s[i]+dis_from_d[i]);

        cout<<"Case "<<cs<<": "<<ans<<"\n";
    }

    return 0;
}
```

 Happy coding! :3
