# LOJ 1082 - Array Queries

The problem statement is very clear. The only difficulty you will face here is the time limit. Naive approach will give TLE. Then what do we need to solve this problem? We could use Cumulative Sum technique if the problem wanted sum of ranges but Cumulative Sum doesn't work for min/max type problems. We need an efficient data structure. We can use Segment Tree. If you know about this data structure then you will notice that a basic Segment Tree implementation will be enough to solve this problem.

### Helpful resources:

* [Recursion tutorial - Smilitude](https://sites.google.com/site/smilitude/recursion_and_dp)
* [Segment Tree tutorial - Shafaet's blog](http://www.shafaetsplanet.com/?p=1557)
* [Segment Tree theory - Loveextendscode](https://www.youtube.com/watch?v=IQ1Xpn7EUMQ)
* [Segment Tree implementation - Loveextendscode](https://www.youtube.com/watch?v=olgP016uMjY)

### Solution:

First we will build the Segment Tree from the given array. The leaf nodes of the tree will store the array values. Any non-leaf node will store the minimum value of its left child and right child. Then we will just run the given queries on the tree and print the answers. The overall time complexity will be O(NlogN).

Caution: for an array of size N, it is safe to keep the tree size 4*N. To know why, check this out: https://stackoverflow.com/a/28502243

### Code:
#### C++
-----
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> arr;        // For storing input array
vector<int> seg_tree;   // For storing the Segment Tree

// Function for building the Segment tree. Here the parameters are:
// node  -> Index of the current node in the segment tree.
// Begin -> Starting index of the segment of the array we are working on.
// End   -> Ending index of the segment of the array we are working on.
void build(int node, int Begin, int End)
{
    // Leaf node because the size of the segment is 1.
    if(Begin == End)
    {
        seg_tree[node] = arr[Begin];
        return;
    }

    int Left, Right, Mid;
    Left = node*2;                  // Left child of the current node.
    Right = (node*2)+1;             // Right child of the current node.
    Mid = Begin+((End-Begin)/2);    // Middle index of the current segment.
    build(Left, Begin, Mid);        // Building the left subtree for the first half of the current segment.
    build(Right, Mid+1, End);       // Building the right subtree for the second half of the current segment.
    seg_tree[node] = min(seg_tree[Left], seg_tree[Right]);    // Storing the minimum of the two halves in the current node.
}

// Function for running the queries. Here the parameters are:
// node  -> Index of the current node in the segment tree.
// Begin -> Starting index of the segment of the array.
// End   -> Ending index of the segment of the array.
// I     -> Starting index of the range we are running query on.
// J     -> Ending index of the range we are running query on.
int query(int node, int Begin, int End, int I, int J)
{
    // Current segment and query range don't intersect. This segment has no contribution.
    if(End<I || J<Begin)
        return INT_MAX;

    // Current segment is inside query range. This segment has contribution.
    if(I<=Begin && End<=J)
        return seg_tree[node];

    // Current segment and query range partially intersect. So we have to go deeper.
    int Left, Right, Mid, q1, q2;
    Left = node*2;
    Right = (node*2)+1;
    Mid = Begin+((End-Begin)/2);
    q1 = query(Left, Begin, Mid, I, J);     // Running query on the first half of the current segment.
    q2 = query(Right, Mid+1, End, I, J);    // Running query on the the second half of the current segment.
    return min(q1, q2);                     // Returning the minimum of the relevant part of the two halves of the current segment.
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

        build(1, 1, n);    // Building the Segment Tree
        cout<<"Case "<<cs<<":"<<"\n";

        for(int i=1; i<=q; i++)
        {
            int I, J;
            cin>>I>>J;
            cout<<query(1, 1, n, I, J)<<"\n";    // Running query on the given range.
        }
    }

    return 0;
}
```

 Happy coding! :3
