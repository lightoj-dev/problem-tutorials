# LOJ - 1112: Curious Robin Hood

-----

**General Approach :** The problem is a straight forward update and query problem. Using a `Binary Indexed Tree` or `segment tree` easily solves the problem.

**How to know I have to use a special data-structure? :** The main question that arrives in solving this problem is how do I identify which data structure to use or why wont using a normal array be enough. The answer is within the time-limit and constraint. If we use a simple array and take a brute forced approach we can update any point in the array in `O(1)` time. But for every query for finding the sum within the given range will take `O(N)` time.

Since an array can contain up to 10^5 elements and number of queries can be max 50000 for each test case, in the event that max number of elements is given and each query is to find a sum of elements in a large range number of operations performed crosses the threshold of `10^8` instructions , which is the standard for solving problems in O(N) time. This means we need an approach with faster time complexity with the minimum being `O(logN)`.

Two Data structures that has time-complexity of O(logN) or better for both query and update are `segment tree` and `Binary Indexed Tree` or Fenwick tree. Since , Binary Indexed tree (Fenwick tree) is shorter and easier to implement we decided on using it.

**Resources :** If you have no idea about Binary Indexed tree it's recommended that you watch the video series first and then try to implement the code by yourself.

* [Binary Indexed Tree Blog](https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/)
* [Binary Indexed Tree range query video](https://www.youtube.com/watch?v=RgITNht_f4Q&t=0s)
* [Binary Indexed Tree point update](https://www.youtube.com/watch?v=B-BkW9ZpKKM&t=0s)
* [Binary Indexed Tree Construction](https://www.youtube.com/watch?v=BHPez138yX8&t=0s)

-----

**Solution Code in C++ :**

```cpp
#include <bits/stdc++.h>
using namespace std;

int tree[100005]; // For constructing BIT (Binary indexed tree)
int arr[100005];  // For the normal inputted values of array.

//for querying value for Binary Indexed tree
int BIT_Query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx=idx - (idx& -idx);
    }
    return sum;
}

//for updating value of binary indexed tree
void BIT_Update(int n, int idx, int val)
{

    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=(idx& (-idx));
    }
}

//for constructing the binary indexed tree
void BIT_Build(int n)
{
    for(int i=1; i<=n; i++)
    {
        BIT_Update(n, i, arr[i]);
    }

}

int main()
{
    int t, cn=0;
    cin>>t;

    while(t--)
    {
        int n, q;
        cin>>n>>q;

        tree[0]=0;

        for(int i=1; i<=n; i++)
        {
            cin>>arr[i];
            tree[i]=0;
        }

        BIT_Build(n);

        cout<<"Case "<<++cn<<":\n";

        while(q--)
        {
            int l, r, type;
            cin>>type;

            if(type==1)
            {
                cin>>l;

                // plus one is added because we are using an array indexed from one within the code.
                int val=arr[l+1];
                arr[l+1]=0;

                cout<<val<<'\n';

                BIT_Update(n, l+1, -val);
            }
            else if(type==3)
            {
                cin>>l>>r;

                // two queries are used to calculate sum within range of r to l
                int val = BIT_Query(r+1)-BIT_Query(l);
                cout<<val<<'\n';
            }
            else
            {
                int val,loc;
                cin>>loc>>val;

                arr[loc+1]=arr[loc+1]+val;
                BIT_Update(n, loc+1, val);
            }
        }

    }
    return 0;
}

```
