# LOJ-1009: Back to Underworld
---
**What the problem wants :** You will be given 'n' number of fights between lykans and vampires. The fight will be given as two numbers 'u' and 'v'. And we have to find the maximum number of lykan or vampire. We will need to output the maximum number of members, not which faction they belong to.

**General approach to solution :** This can be identified as a graph problem. Where 'n' is the number of edges in a graph and 'u' and 'v' are connected nodes of an edge. lets consider the fact that each node can either represent a lykan or a vampire and can never be both. This means there can be at most two types of nodes. The answer will be the maximum between the sum of nodes. If there is total 10 nodes that are lykan and 5 that are vampire (or vice-versa) than the answer will be 10.
One thing to remember is we can't explicitly say which node is lykan or vampire and we don't need to either.

So these are the steps we will take to solve the problem:
  1. Create an adjacency matrix for the graph.
  2. Use a modified BFS on each node to mark them as either a lykan or vampire node.
  3. Find the sum of each type of node, compare two sums and the highest one will be our answer.   

**Technical Notes :** The input dataset for this problem is huge. This means using any inefficient method for taking inputs will result in exceeding the time limit. So, make sure to use very fast implementation of input and output methods of which ever language you are using. For example:
in C++ using "cin" & "cout" might result in time limit exceeding even if the entire implementation is algorithmically correct . This can be avoided by using "scanf" and "printf".

**Additional Resources:** If you don't know what BFS, adjacency matrix or graphs are you can check these awesome resources:
  * [Graph Representation by geeksforgeeks](https://www.geeksforgeeks.org/graph-and-its-representations/)  
  * [Breadth First Search(BFS) by wikipedia](https://en.wikipedia.org/wiki/Breadth-first_search)
  * [BFS visualization by william fiset on youtube](https://www.youtube.com/watch?v=oDqjPvD54Ss)
  * [BFS explanation by Reducible](https://www.youtube.com/watch?v=xlVX7dXLS64)
---
## Solution Code
Here's an accepted code in _C++_ for the problem. Remember to carefully consider the constraints while implementing your own solution , such as using fast input output methods and allocating enough memory if you use arrays, because the input dataset is humongous.

**Code :**
```cpp
//LOJ-1009 Back to Underworld
#include <bits/stdc++.h>
using namespace std;

vector<int> vec[20009]; // for creating adjacency matrix.
bool vis[20009]= {};
bool node_type[20009]= {};

long long int bfs(int x);

//utility function to reset all data-structures values to zero.
void clr()
{
    memset(vis,false,sizeof (vis));
    memset(node_type,false,sizeof (node_type));
    for(int i=0; i<20009; i++)
        vec[i].clear();
}

long long int modified_bfs(int x); //this function is implement after the main function

int main()
{
    int T,u,v,n,case_num=1;
    scanf("%d",&T);

    while(T--)
    {
        clr(); //resetting all arrays before starting to process each test case.

        scanf("%d",&n);
        long long int sum=0;

        while(n--)
        {
            scanf("%d %d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        for(int i=0; i<20009; i++)
        {
            if(vis[i]==0 && !vec[i].empty())
            {
                sum+= modified_bfs(i);
            }
        }
        cout<<"Case "<<case_num++<<": "<<sum<<'\n';
    }
    return 0;
}
long long int modified_bfs(int x)
{
    long long int lykan_num=0,vampire_num=0;
    queue<int>q;

    q.push(x);
    vis[x]=1;
    node_type[x]=1;
    ++lykan_num;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0; i<vec[u].size(); i++)
        {
            int v = vec[u][i];
            if(vis[v]==0)
            {
                q.push(v);
                vis[v]=1;

                if(node_type[u]==1) //assigning type to each node.
                {
                    node_type[v] = 0;
                    ++vampire_num;
                }
                else
                {
                    node_type[v] = 1;
                    ++lykan_num;
                }
            }
        }
    }

    long long int mx = max(vampire_num,lykan_num);

    return mx;
}

```
