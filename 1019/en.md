# LOJ 1019: Brush (V)
### What the problem wants
We are given a graph of N nodes and M edges (two way). Each edge is given as tuple (u, v, w) resembling that there is an edge between u and v with distance w. We need to find the least distance from node 1 to node N (or print "Impossible" if it is indeed impossible to reach from node 1 to node N).


### General Approach
The problem can be solved by the Dijkstra algorithm that uses modified BFS traversal to choose the least distance to traverse from node 1 to node N. 
- At first we are going to keep a track of distance of all the nodes from node 1 (in an array). As we haven't started traversing yet, we will put infinity (or quite a large number) as the distance (of course distance[1] will always be zero, distance between node 1 and node 1 is zero indeed :D ).
- We also maintain a data structure that sorts (ascendingly) itself according to the distance from node 1 (priority queue works well for this). Initially it is empty. We put node 1 in this queue.
- We start extracting the first node, u, from the priority queue. We go to all the nodes, v, that are adjacent to u and check if summation of distance of u (from node 1) and distance from node u to v is less than distance of v (from node 1). If yes, then we relax the node v; that means we update the distance of node v (from node 1) and we put node v into the priority queue. We continue this process untill the queue is empty. After finishing, we can just check the distance of node n from node 1 by looking at the distance array only.
- Additional check is needed to see if node n is reachable from node 1. Can you tell me what happens if distance of node n from node 1 is still infinity (or the large number that was assigned in the beginning at the first step) after all the traversal?

### Caution
Do not forget to clear stored informations (about nodes, edges) after/before each test cases.

### Things to learn
Dijkstra algorithm, BFS-DFS, Graph traversal

### C++ implementation
```
#include <bits/stdc++.h>
using namespace std;

const int N = 102;

int n, m;
int u, v, w, dis[N];
vector< pair<int, int> > node[N];


void minimize_dis(int src, int dest) {
  for(int i = 1; i <= n; i++) dis[i] = INT_MAX;
  dis[src] = 0;
  priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
  q.push({dis[src], src});
  while(!q.empty()) {
    auto p = q.top();
    q.pop();
    for(auto &nd: node[p.second]) {
      if( dis[nd.first] > dis[p.second] + nd.second ) {
        dis[nd.first] = dis[p.second] + nd.second;
        q.push({dis[nd.first], nd.first});
      }
    }
  }
}

void clear() {
	for(int i = 1; i <= n; i++) node[i].clear();
}

int main() {
  int cs;
  scanf("%d", &cs);
  for(int tc = 1; tc <= cs; tc++) {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
      scanf("%d %d %d", &u, &v, &w);
      node[u].push_back({v, w});
      node[v].push_back({u, w});
    }
    minimize_dis(1, n);
    if(dis[n] == INT_MAX) {
      printf("Case %d: Impossible\n", tc);
    } else {
      printf("Case %d: %d\n", tc, dis[n]);
    }
    clear();
  }
}
```