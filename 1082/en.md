# LOJ 1082 - Array Queries

The problem statement is very clear. The only difficulty you will face here is the time limit. Naive approach will give TLE. Then what do we need to solve this problem? We could use Cumulative Sum technique if the problem wanted sum of ranges but Cumulative Sum doesn't work for min/max type problems. We need an efficient data structure. We can use Segment Tree. If you know about this data structure then you will notice that a basic Segment Tree implementation will be enough to solve this problem.

### Helpful resources:

* [Recursion tutorial - Smilitude](https://sites.google.com/site/smilitude/recursion_and_dp)
* [Segment Tree tutorial - Shafaet's blog](http://www.shafaetsplanet.com/?p=1557)
* [Segment Tree theory - Loveextendscode](https://www.youtube.com/watch?v=IQ1Xpn7EUMQ)
* [Segment Tree implementation - Loveextendscode](https://www.youtube.com/watch?v=olgP016uMjY)

### Solution:

First we will build the Segment Tree from the given array. The leaf nodes of the tree will store the array values. Any non-leaf node will store the minimum value of its left child and right child. Then we will just run the given queries on the tree and print the answers. The overall time complexity will be O(NlogN).

Caution: for an array of size N, keep the tree size 4*N. To know why, check this out: https://stackoverflow.com/a/28502243

### Code:
#### C++
-----
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> arr, seg_tree;

void build(int node, int Begin, int End)
{
    if(Begin == End)
    {
        seg_tree[node] = arr[Begin];
        return;
    }

    int Left, Right, Mid;
    Left = node*2;
    Right = (node*2)+1;
    Mid = Begin+((End-Begin)/2);
    build(Left, Begin, Mid);
    build(Right, Mid+1, End);
    seg_tree[node] = min(seg_tree[Left], seg_tree[Right]);
}

int query(int node, int Begin, int End, int I, int J)
{
    if(End<I || J<Begin)
        return INT_MAX;

    if(I<=Begin && End<=J)
        return seg_tree[node];

    int Left, Right, Mid, q1, q2;
    Left = node*2;
    Right = (node*2)+1;
    Mid = Begin+((End-Begin)/2);
    q1 = query(Left, Begin, Mid, I, J);
    q2 = query(Right, Mid+1, End, I, J);
    return min(q1, q2);
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
        int n, q;
        cin>>n>>q;
        arr.assign(n+2, 0);
        seg_tree.assign((4*n)+2, 0);

        for(int i=1; i<=n; i++)
            cin>>arr[i];

        build(1, 1, n);
        cout<<"Case "<<cs<<":"<<"\n";

        for(int i=1; i<=q; i++)
        {
            int I, J;
            cin>>I>>J;
            cout<<query(1, 1, n, I, J)<<"\n";
        }
    }

    return 0;
}
```

 Happy coding! :3
