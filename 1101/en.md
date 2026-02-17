# LightOJ 1101 – A Secret Mission

## Problem Summary

We are given a connected weighted graph with `N` cities and `M` roads.
Each road has a *danger value*.

For each query `s t`, we must find a path from `s` to `t` such that:

> the maximum danger of any road on the path is minimized.

This is known as a **minimax path problem**.

---

## Key Observation

If we build a **Minimum Spanning Tree (MST)** of the graph, then:

> For any two nodes, the path between them in the MST minimizes the maximum edge weight among all possible paths in the original graph.

Why is this true? Intuitively, in an MST every edge is as "cheap" as possible: if there were a path between two nodes whose maximum edge could be made smaller by taking some other route in the original graph, we could replace the larger edge on the MST path with that smaller edge and still keep the graph connected. That would give us another spanning tree with strictly smaller maximum edge on that path, contradicting the fact that the original tree was minimum. So for any pair of nodes, the path inside the MST uses edges that are as small as possible, and the largest edge on that MST path is the smallest possible "bottleneck" among all paths in the original graph.

Therefore, once we construct the MST, we only need to answer queries on that tree.

---

## Strategy

1. Build the MST using **Prim’s algorithm**
2. Convert the graph into a tree
3. Preprocess the tree using **Binary Lifting**
4. Store:

   * `anc[u][i]` → `2^i`-th ancestor of node `u`
   * `mx[u][i]` → maximum edge weight from `u` to its `2^i`-th ancestor
5. For each query:

   * compute LCA of `u` and `v`
   * find maximum edge on path (`u` to LCA) and (`v` to LCA) using binary lifting
   * answer = max of the two above values.

---

## Complexity

* MST construction: `O(M log N)`
* Binary lifting preprocessing: `O(N log N)`
* Each query: `O(log N)`

This easily fits within constraints.

---

## Implementation

```cpp
#include<bits/stdc++.h>
using namespace std;

// Constants
const int N = 50005, LOG = 18;  // N = max nodes, LOG = ceil(log2(N)) for binary lifting

// Graph structures
vector<pair<int,int>> mainGraph[N]; // Original graph edges: {neighbor, weight}
vector<pair<int,int>> MST[N];       // Minimum Spanning Tree edges
bool vis[N];                        // Visited array for MST construction

// Binary lifting tables
int anc[N][LOG]; // anc[node][i] = 2^i-th ancestor of node
int mx[N][LOG];  // mx[node][i] = maximum edge weight from node to its 2^i-th ancestor
int dep[N];      // Depth of each node in the MST (rooted at 1)


// Clear all globals for new test case
void clear() {
    for(int i = 0; i < N; i++){
        vis[i] = false;
        mainGraph[i].clear();
        MST[i].clear();
    }
    // due to the constraints of the problem it's feasible to clear the entire thing up to N
    memset(anc, 0, sizeof(anc));
    memset(mx, 0, sizeof(mx));
    memset(dep, 0, sizeof(dep));
}


// Create MST using Prim's algorithm and store it in MST[]
void createMST() {
    // Min-heap for Prim's: stores {weight, node, parent}
    priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
    > pq;

    pq.push({-1, 1, 0}); // Start from node 1, with "fake" edge weight -1

    while(!pq.empty()){
        int wt, node, parent;
        tie(wt, node, parent) = pq.top(); 
        pq.pop();

        if(vis[node]) continue; // Already included in MST

        vis[node] = true;

        if(parent != 0){
            // Add edge to MST (undirected)
            MST[parent].push_back({node, wt});
            MST[node].push_back({parent, wt});
        }

        // Push all adjacent edges to PQ
        for(auto child: mainGraph[node]){
            if(!vis[child.first]){
                pq.push({child.second, child.first, node});
            }
        }
    }
}


// DFS on MST to compute depth, ancestor table, and max edge table for binary lifting
void dfs(int node, int par = 0, int wt = 0){
    
    dep[node] = dep[par] + 1; // Set depth
    anc[node][0] = par;       // 2^0-th ancestor is immediate parent
    mx[node][0] = wt;         // Max edge to parent

    // Binary lifting preprocessing
    for(int i = 1; i < LOG; i++){
        anc[node][i] = anc[anc[node][i-1]][i-1]; // 2^i-th ancestor
        mx[node][i] = max(mx[anc[node][i-1]][i-1], mx[node][i-1]); // Max edge to 2^i-th ancestor
    }

    // DFS to children
    for(auto child: MST[node]){
        if(child.first != par){ // Avoid going back to parent
            dfs(child.first, node, child.second);
        }
    }
}


// Find LCA (Lowest Common Ancestor) of two nodes using binary lifting
int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v); // Make u deeper

    // Lift u up to same depth as v
    for(int i = LOG-1; i >= 0; i--){
        if(dep[anc[u][i]] >= dep[v]){
            u = anc[u][i];
        }
    }

    if(u == v) return u; // If one is ancestor of the other

    // Lift both u and v until their ancestors match
    for(int i = LOG-1; i >= 0; i--){
        if(anc[u][i] != anc[v][i]){
            u = anc[u][i];
            v = anc[v][i];
        }
    }

    return anc[u][0]; // Return their parent (LCA)
}


// Maximum edge weight on path from node to its ancestor 'l'
int maxedge(int node, int l){
    int dis = dep[node] - dep[l]; // Distance from node to ancestor
    int ans = 0;

    // Lift node up to ancestor while tracking max edge
    for(int i = LOG-1; i >= 0; i--){
        if(dis & (1 << i)){
            ans = max(ans, mx[node][i]);
            node = anc[node][i];
        }
    }
    return ans;
}


// Query maximum edge weight between two nodes u and v
int query(int u, int v){
    int l = lca(u, v); // Find LCA
    return max(maxedge(u, l), maxedge(v, l)); // Max edge from u->LCA and v->LCA
}


int tc = 1; // Test case counter
void SOLVE(){
    cout << "Case " << tc++ << ":" << "\n";

    int n, m; 
    cin >> n >> m;
    clear();

    // Read graph
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        mainGraph[a].push_back({b, c});
        mainGraph[b].push_back({a, c});
    }

    createMST();
    dfs(1); 
    // The original problem guarantees the graph (and thus the MST) is connected,
    // so we can safely root the DFS at node 1. If used on arbitrary graphs,
    // ensure connectivity or run DFS from all components.


    int q;
    cin >> q;

    while(q--){
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << "\n"; 
    }
}   


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) SOLVE();
    return 0;
}

```

---

## References

* https://cp-algorithms.com/graph/mst_prim.html
* https://cp-algorithms.com/graph/lca_binary_lifting.html

---

**Author:** Sadat
