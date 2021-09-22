# LOJ - 1112: Curious Robin Hood

-----
**What the problem Wants :** The problem gives you an array of `n` elements , where you must perform three types of pre-defined query .
these queries are:

1. 1 i - give all the money of the ith index and print the amount given .
2. 2 i v - add money v to the ith sack.
3. 3 i j - find the total amount of money from the ith sack to the jth sack and print the amount

Lets see what these queries mean on an example case.

``` none
1
5 3
1 2 3 4 5  // the given array
1 3        // queries of type -1
2 4 10     // queries of type -2
3 2 4      // queries of type -3 
```

**Output :**

``` none
Case 1:
4
18
```

In the above example:

after quary of type-1 the array is { 1 , 2 , 3 , _0_ , 5 }

after quary of type-2 the array is { 1 , 2 , 3 , _0_ , _15_ }

after query of type-3 the array is { 1 , 2 , 3 , _0_ , _15_ } which is the same . However at this step the output will be 18 , denoting the sum of all elements in the array from the index-2 to index-4.

**General Approach :** The problem is a straight forward update and query problem. We can use a brute force approach which although solves the problem , doesn't meet our constraint for required time. As a brute force approach is too slow. Using a `Binary Indexed Tree` or `segment tree` however easily solves the problem within the time constraint.

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
