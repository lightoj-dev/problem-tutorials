## Problem Id: LOJ-1041
## Problem Name: Road Construction

## Prerequisite:
1. Graph Traversal (BFS/DFS)
2. Minimum Spanning Tree (Kruskal/Prim's Algorithm)

## Problem at a glance:
In this problem we will have to check two vital things:
1. If all cities are reachable from any city to other
2. Minimum cost needed to repair the roads

For convenience we will divide the whole problem into two sub problems.

### Sub Problem 1:
To solve this problem we need to know if all the cities are directly or indirectly connected to others. It can be solved in two ways ; 
- we can check if all the cities compose a single connected component 
- We may traveres the whole graph once and then check if all the nodes/cities are visited or not. 

For my convenience I will implement this in a different way.

### Sub Problem 2:
This sub problem is straight forward. We need to repair the roads and make all the cities connected. But to repair the road we will have to spend some money. So we will repair those roads which have least cost. That is why we can sort the road connection with their cost in ascending order. Then we will try to connect the roads with one another. You will be able to relate the solution of this sub problem if you know about **Minimum Spanning Tree**. I suggest to have a read on this topic and learn **Prim's  and Kruskal's Algorithm**. This algorithm will help us to build a graph with least cost. In my solution I've implemented Kurskal's Algorithm.

### Code

```
#include <bits/stdc++.h>

using namespace std;


struct NewData
{
    string city1, city2;
    int cost;
} vr;

bool operator<(struct NewData d1, struct NewData d2)
{
    return d1.cost < d2.cost;
}

vector<NewData> graph;
map<string, bool> Checked;
map<string, string> parent;
set<string> st;
map<string, set<string>> mp;

void ClearAll()
{
    graph.clear();
    Checked.clear();
    parent.clear();
    st.clear();
    mp.clear();
}

string findParent(string s)
{
    if (parent[s] == s)
        return s;
    return findParent(parent[s]);
}

int MinCost()
{
    int res = 0;
    for (auto x : st)
    {
        parent[x] = x;
    }
    for (auto x : graph)
    {
        string s = x.city1;
        string s2 = x.city2;
        string ps = findParent(s);
        string ps2 = findParent(s2);
        if (ps != ps2)
        {
            res += x.cost;
            parent[ps2] = ps;
        }
    }
    return res;
}

int bfs(string s)
{
    int res = 0;
    queue<string> q;
    q.push(s);
    Checked[s] = true;
    res++;
    while (!q.empty())
    {
        string cur = q.front();
        q.pop();
        for (auto x : mp[cur])
        {
            if (!Checked[x])
                Checked[x] = true, q.push(x), res++;
        }
    }
    return res;
}

int main()
{
    int t, cs = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ClearAll();
        while (n--)
        {
            cin >> vr.city1 >> vr.city2 >> vr.cost;
            graph.push_back(vr);
            st.insert(vr.city1);
            st.insert(vr.city2);
            mp[vr.city1].insert(vr.city2);
            mp[vr.city2].insert(vr.city1);
        }
        sort(graph.begin(), graph.end());
        string ans = "";
        int mnCost = MinCost();
        ;
        if (bfs(*st.begin()) != st.size())
            ans = "Impossible\n";
        cout << "Case " << cs++ << ": ";
        if (ans.size() > 0)
            cout << ans;
        else
            cout << mnCost << endl;
    }
    return 0;
}
```

## Resources:
- [BFS] (https://cp-algorithms.com/graph/breadth-first-search.html)
- [DFS] (https://cp-algorithms.com/graph/depth-first-search.html) 
- [Kruskal] (https://cp-algorithms.com/graph/mst_kruskal.html) 
- [Prim's] (https://cp-algorithms.com/graph/mst_prim.html)


### Tutorial by:
Profile Link: [Hasibur Rahman] (https://lightoj.com/user/evan13)