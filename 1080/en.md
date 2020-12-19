# Loj 1080 - Binary Simulation

_Given a binary number, we are about to do some operations on the number. Two types of operations can be here._

_`‘I i j‘` which means invert the bit from `i` to `j`_ (inclusive)

_`‘Q i‘` answer whether the ith bit is `0` or `1`_

_The MSB (most significant bit) is the first bit (i.e. i=1). The binary number can contain leading zeroes._

---

#### Summary

For the `T` group of input set, where each set consist of `S`, a binary bit pattern, and `Q`, number of queries, for each queries you have invert a range in the given bit pattern or answer if the asked bit is set/`1` or not/`0`.

#### Solution

It's clear that a naive approach of updating range in `O(N)` complexity will make `O(Q*N)` complexity for `Q` queries, which will give `TLE` in this input range. So you have to look for a faster way to make these queries.

There are many Data structures, _segment tree_, _binary index tree_, for example, to handle this type of _range update and point query_ or _point update range query_ in a faster way.

In this tutorial you will use the logic of the segment tree lazy propagation. If you aren't already aware of Segment Tree and Lazy Propagation, have a walk through these links:

- [Hackerearth: Segment Tree and Lazy Propagation](https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/)
- [Cp-Algorithm: Segment Tree and it varieties](https://cp-algorithms.com/data_structures/segment_tree.html)

Let's assume you got a proper knowledge on what is segment tree and how does lazy propagation works.

As there are two types of queries, for _update range_ query, rather than updating the range instantly, if you just _keep a track_ or _mark the node_, so that next time you go down to this node you will be aware of pending updates to make updates on it's predecessors, and for the second type of queries, while finding the desired node, make the pending updates and store the latest status of that node.

_**Fact**: as the input string is consist of only 0 and 1, and the type of update is only inverting the index, no matter how many inversions you make it will be same in each `even` inversion count and vise versa, `1` will remain `1` after 2,4,6,.. inversions and will become `0` after 1,3,5,.. inversions, for example._

Let's have a walk through a visual example:

Let's say you have an array named **nodes** contains the tree.
Initially value of all the nodes will be `0`.
Now for any type of inversion query, make a function call named `invertRange` that will find out and mark the node that needed to be marked with pending update in `O(log N)` time complexity. Same rules go for the given bit pattern as well.

For bit status query, call a function `query` that will walk though the nodes and process it's pending updates/inversions, starting from the root node to the desired node.

```
input:
1
1 4
1011001

I 1 7
Q 4
I 5 5
Q 1
```

<img width="1200" alt="initial" src="https://user-images.githubusercontent.com/27924505/102653205-db98f100-4198-11eb-85ef-05b90cd8735e.png">

<img width="1200" alt="input" src="https://user-images.githubusercontent.com/27924505/102653261-f23f4800-4198-11eb-81f4-8935fb8698b2.png">

<img width="1200" alt="Q1" src="https://user-images.githubusercontent.com/27924505/102653299-01be9100-4199-11eb-8a42-afea805deebd.png">

query-1: _you can see there is a pending update on root (1-7) node._

<img width="1200" alt="Q2" src="https://user-images.githubusercontent.com/27924505/102683002-db7c0e00-41f7-11eb-9989-d66b21d99524.png">

query-2: _pending updates shifted shown to the (1-2) and (5-7) range nodes and no pending ad on (2-4) as it's already made the updates in it's predecessors_

<img width="1200" alt="Q3" src="https://user-images.githubusercontent.com/27924505/102683001-da4ae100-41f7-11eb-920d-7c625cbf5bca.png">

query-3: _pending update (5-7) shifted down and as (5,5) already had a pending update, with another inversion request it remains same with even inversion counts._

<img width="1200" alt="Q4" src="https://user-images.githubusercontent.com/27924505/102683000-d8811d80-41f7-11eb-962d-637c406ac30d.jpg">

query-4: _no more pending updates in (1-2) as it's predecessors get updated_

#### Code

### C++

```cpp
#include "bits/stdc++.h"

using namespace std;

const int mx = 100005;

bool nodes[4*mx];

void invertRange(int v, int tl, int tr, int l, int r){

	if(tl==l and tr==r){
		nodes[v] = !nodes[v];
		return;
	}

	int tm = (tr+tl)/2;

	// if the segment in the left
	if(r<=tm)
		invertRange(2*v, tl, tm, l, r);
	// if the segment in the right
	else if(tm<l)
		invertRange(2*v+1, tm+1, tr, l, r);
	else{
		invertRange(2*v, tl, tm, l, tm);
		invertRange(2*v+1, tm+1, tr, tm+1, r);
	}
}

int query(int v, int tl, int tr, int pos){

	if(tr==pos and tl==pos)
		return nodes[v];

	int tm = (tl+tr)/2;

	if(pos<=tm)
		return nodes[v] + query(v*2, tl, tm, pos);
	else
		return nodes[v] + query(v*2+1, tm+1, tr, pos);
}

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);

	int t, cs = 1;
	for (cin >> t; cs <= t; cs++) {
		printf("Case %d:\n", cs);

//		create_tree(a, nodes, n);
		memset(nodes, 0, sizeof(nodes));

		string str;
		cin >> str;
		int len = str.size();

		// insert input data
		for (int i = 0; i < len; i++)
			if(str[i]=='1')
				invertRange(1,1,len,i+1,i+1);

		int q,x,y;
		cin >> q;

		for (int i = 0; i < q; i++) {
			char choice;
			cin >> choice;
			switch(choice) {
				case 'I':
					cin >> x;
					cin >> y;
					invertRange(1, 1, len, x, y);
					break;

				case 'Q':
					cin >> x;
					printf("%d\n", (query(1,1,len,x) %2));
					break;
			}
		}
	}
    return 0;
}
```
