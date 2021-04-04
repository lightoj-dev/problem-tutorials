# LOJ-1063 - Ant Hills
---
Tags : graph, articulation points

### Helpful Resources

* [Graph (abstract data type) - Wikipedia](https://en.wikipedia.org/wiki/Graph_(abstract_data_type) "Graph (abstract data type) - WikiPedia")

* [Articulation Point algorithm - Hackerearth](https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/ "Articulation Point algorithm")

* [Articulation Point Code - cp-algorithms](https://cp-algorithms.com/graph/cutpoints.html "Articulation Point code")


## Solution

Upon reading the question it is clear that we can represent the ants hills civilisation in terms of a graph
where every ant-hill can be considered as a vertex in the graph, now according to the problem we need to find
the number of ant hills such that the graph can get disconnected or in other words it breaks the graph into two 
or more components if we delete that node therefore removal of leaf nodes is not considered in this as we are 
deleting the node, So it plainly boils down to the topic of articulation points and the way to solve them is through
implementation using Tarjan's algorithm. I have added the resources above for understanding and also have commented some
corner cases inside the code where understanding can be missed, so those can be helpful.


## Time Complexity

- Runtime for a single testcase for Tarjan's algorithm is linear `O(E+V)`
 
The above implementation is `accepted`.

## Solution in C++
```cpp

#include "bits/stdc++.h"
using namespace std;

////////////////////////////////////////////////
//   Author: Vikram Singh                     //
//   Handle: maverickjoy                      //
//   Github: https://github.com/maverickjoy   //
////////////////////////////////////////////////


// Run -> g++ -std=c++11 try.cpp

#define ll long long
#define endl "\n"

int timer = 0;
vector<bool>vis;
vector<int>disc;
vector<int>low;
vector<bool>is_cut;
vector<vector<int> >adj;


// this function can be called multiple times for the same node
void isArticulationPoint(int node) {
    is_cut[node] = true;
}

void dfs(int node, int pn)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int children = 0;

    for(int child : adj[node])
    {
        if(child == pn) continue;
        if(vis[child]) // back edge
        /*
            - As in the case of articulation bridges we could even
              use low[child] instead of disc[child] because that time we were just
              considering edge not node now when node comes there is again a corner
              case where it can fail, hence always use disc[child] than low[child]
              if the child is already visited.
              For visualisation check below graph:

              Marking final (discovery_time, low_time)

               (1,1)            (4,3)
                1                 4
                |  \          /  |
                |    \(3,1) /    |
                |       3        |
                |   /      \     |
                2 /          \   5
                (2,2)           (5,3)

              So here you can clearly see if we would have taken low_time of 3,
              which is 1 in this case at the time when we were considering for
              node 5, then 3 wouldnt have been cut vertex, as low time for child
              4 =>[1] would have been less than discovery time of 3 =>[3].
              But as you can see it is part of two cycles it would have
              disconnected the graph into 2 components once removed therefore its
              a cut vertex. Hence we consider disc[child] than low[child].
        */
            low[node] = min(low[node], disc[child]);
        else
        {
            children += 1;
            dfs(child, node);
            low[node] = min(low[node], low[child]);


            /*
                - Remember to add par node condtition to this since root node of
                  the dfs tree is not eligible for this condition according to
                  Tajans algo
                - Second Point unlike in bridges why do we also include `=` for
                  the condition    `disc[node] <= low[child]`.
                  Reason is it is a corner case we need to even include nodes with
                  same times. For visualisation check below graph.

                  Marking final (discovery_time, low_time)


                  (1, 1)     (2, 2)    (3, 2)
                  1 --------- 2 ------3
                              \      /
                              \   /
                                4
                                (4, 2)
                  Since for 2 discovery time and low time for child 3 are same,
                  but on removal of node 2 graph will break and components will
                  increase therefore equal to is needed.
            */
            if(disc[node] <= low[child] && pn != -1)
                isArticulationPoint(node);
        }
    }
    if(children > 1 && pn == -1) // root node with more than one child
        isArticulationPoint(node);
}

void cleanup()
{
    timer = 0;
    vis.clear();
    disc.clear();
    low.clear();
    adj.clear();
    is_cut.clear();
}


void hk()
{
    cleanup();
    int n, m, u, v, e;
    cin>>n>>m;

    vis.resize(n+1, false);
    disc.resize(n+1, -1);
    low.resize(n+1, -1);
    is_cut.resize(n+1, false);
    adj.resize(n+1, vector<int>());

    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i, -1);
    int ans = 0;
    for(int i=1;i<=n;i++)
        if(is_cut[i])
            ans += 1;

    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<": ";
        hk();
    }
    return 0;
}



```
## Author

- Vikram Singh 
- Find me at [linkedin](https://www.linkedin.com/in/maverickvikram/)