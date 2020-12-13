# LOJ 1059 - Air Ports

### Problem Summary

You are given `n` cities. And permission to build `m` bi-directional roads. For every road, there is a certain cost `c` of building it. You are also given a cost `a`, cost of building an airport in any city. Initially, there is no airport. Your task is to make sure every city is connected to an airport. The airport could be directly located in the city or could be reachable by some path.

You have to `construct roads from the given road list` and `build one or more airports` to satisfy the conditions. And do so at the `smallest cost possible`.

#### If there are multiple solutions with the same cost, pick one with the most airports.

### Observations

We can see the following properties in the problem structure.

- **Graph**: We can consider the cities as `nodes` in a graph, and the roads as `edges`. Since the costs of building roads are given, and the roads are bi-directional, so this is a `Weighted Undirected Graph`.

- **Multi-Components**: Note that, every node in the graph does not need to be connected to each other by roads. They need to be connected to some airports. So the graph we will ultimately construct `may have multiple components`.

- **Tree**: Since only one path to any airport is enough for any city, we can `drop some roads` or edges and `convert the component into a tree` to save total construction cost.

- **Minimum Spanning Tree**: For the road network to have the `smallest possible construction cost`, we can compute the `minimum spanning tree` of the graph component.

  - `Minimum Spanning Tree` of a graph is a subtree of that graph that contains all the `nodes` and the `sum of edge weights` is minimum possible. You can use [Prim's algorithm](https://cp-algorithms.com/graph/mst_prim.html) or [Kruskal's Algorithm](https://cp-algorithms.com/graph/mst_kruskal.html) to implement the Minimum Spanning Tree.

- **Road vs Airport**: If a road has an equal or higher cost of construction than an airport, it is always better to build an airport. Because if there are `multiple solutions with the same cost`, we have to `maximize airports`.

- **One Airport Per Component**: `Every component should have only one airport`. Because having more than one airport will only increase the cost.

### Solution

- When taking edge inputs, if the edge cost is equal or higher than airport cost, do not insert it into the edge list.

- The graph may have multiple components initially, or ignoring some edges during input may create some. `Kruskal's Algorithm` that uses Disjoint-Set Union can be used to compute MST in all components at once.

- Check `how many components` are there, by storing the parents of every disjoint-set element (graph node) into a set. The size of the set is the number of total components.

- Let `mstCost` be the cost of the Minimum Spanning Tree and `airport` be the cost to build one airport and `comps` be the number of components. Then the answer is `mstCost + (airport * comps)`. Along with this, we also have the print `comps` differently, the number of airports needed.

### Simulation

Let us simulate a case with 6 cities.

![Frame 1](https://user-images.githubusercontent.com/14056189/102008348-e6e3bb00-3d59-11eb-82b8-663925441e98.png)
![Frame 2](https://user-images.githubusercontent.com/14056189/102008350-e8ad7e80-3d59-11eb-86d6-fb243afc8cda.png)
![Frame 3](https://user-images.githubusercontent.com/14056189/102008351-e9461500-3d59-11eb-88b5-2f35f02a3665.png)
![Frame 4](https://user-images.githubusercontent.com/14056189/102011618-89f2ff80-3d6f-11eb-987b-d6fa85325b9d.png)

#### Answer:

We need `2` airports. Total cost is `20 + 15 + 10 + 20 + (2 * 50) = 165`.

![Frame 5](https://user-images.githubusercontent.com/14056189/102010758-5cf01e00-3d6a-11eb-8b88-dce382ab3a46.png)

Here is another solution that costs the same but the total airport(s) needed is less than the previous solution. Therefore this is not valid.

### C++

---

```C++
#include<bits/stdc++.h>
using namespace std;
#define MX 100005

struct edge{
    int u, v, w;
};
bool cmp(edge &a, edge &b){
    return a.w < b.w;
}
vector< edge > G; // edge list
int parent[MX];

// function to reset the data structures
void reset(int n){
    G.clear();
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

// function to find parent of a disjoint set
int Find(int u){
    if (u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

// Kruskal's algorithm with Disjoint-Set Union method is used
// minimum spanning tree
int mst(){
    sort(G.begin(), G.end(), cmp);
    int cost = 0;
    for (int i = 0; i < G.size(); i++){
        int p = Find(G[i].u);
        int q = Find(G[i].v);
        if (p != q){
            parent[q] = p;
            cost += G[i].w;
        }
    }
    return cost;
}

int main()
{
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        int n, m, airport;
        scanf("%d%d%d", &n, &m, &airport);

        reset(n);

        for (int i = 1; i <= m; i++){
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            // if edge weight is greater or equal to airport cost
            // we prefer building airport
            if (w >= airport) continue;
            G.push_back({u, v, w});
        }

        int mstCost = mst();

        set<int> comps; // number of components
        for (int i = 1; i <= n; i++){
            // insert parent of every node into the set
            // to get number of components in the graph
            comps.insert(Find(i));
        }
        int total = mstCost + comps.size() * airport;
        printf("Case %d: %d %d\n", cs, total, comps.size());
    }
    return 0;
}
```
