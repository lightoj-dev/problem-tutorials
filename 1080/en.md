# Loj 1080 - Binary Simulation

_Given a binary number, we are about to do some operations on the number. Two types of operations can be here._

_`‘I i j‘` which means invert the bit from `i` to `j`_ (inclusive)

_`‘Q i‘` answer whether the ith bit is `0` or `1`_

_The MSB (most significant bit) is the first bit (i.e. i=1). The binary number can contain leading zeroes._

---

#### Summary

For the `T` group of input set, where each set consist of `S`, a binary bit pattern, and `Q`, number of queries, for each queries you have invert a range in the given bit pattern or answer if the asked bit is set/`1` or not/`0`.

#### Solution

It's clear that a naive approach of `O(N)` complexity will give `TLE` in this input range. So you have to look for a faster way to make queries.

There are many Data structures, _segment tree_, _binary index tree_, for example, to handle this type of _range update and point query_ or _point update range query_ in a faster way.

In this tutorial you will use the logic of the segment tree lazy propagation. If you aren't already aware of Segment Tree and Lazy Propagation, have a walk through these links:

- [Hackerearth: Segment Tree and Lazy Propagation](https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/)
- [Cp-Algorithm: Segment Tree and it varieties](https://cp-algorithms.com/data_structures/segment_tree.html)

Let's assume you got a proper knowledge on what is segment tree and how does lazy propagation works.

As there are two types of queries, for _update range_ query, rather than updating the range instantly, if you just _keep a track_ or _mark the node_, so that next time you go down to this node you will be aware of pending updates to make updates on it's predecessors, and for the second type of queries, while finding the desired node, make the pending updates and store the latest status of that node.

_**Fact**: as the input string is consist of only 0 and 1, and the type of update is only inverting the index, no matter how many inversions you make it will be same in each `odd` inversion count and vise versa, `1` will remain `1` after 1,3,5,.. inversions and will become `0` after 2,4,6,.. inversions, for example._

Let's go through a visual example:

#### Code

### C++

```cpp
#include "bits/stdc++.h"

using namespace std;

const int mx = 100005;

bool sum[4*mx];

void invertRange(int v, int tl, int tr, int l, int r){

	if(tl==l and tr==r){
		sum[v] = !sum[v];
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
		return sum[v];

	int tm = (tl+tr)/2;

	if(pos<=tm)
		return sum[v] + query(v*2, tl, tm, pos);
	else
		return sum[v] + query(v*2+1, tm+1, tr, pos);
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

//		create_tree(a, tree, n);
		memset(sum, 0, sizeof(sum));

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
					printf("%d\n", (query(1,1,len,x) % 2));
					break;
			}

		}

	}

    return 0;
}
```
