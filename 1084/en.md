## Tutorial:

Lets sort the given array.

As we have to add each man to exactly one group, we can start the process from man at first position. If we start making 1 group from position **i**, we can include man of position until **j**, where distance from j person to i is less of equal to 2*k and j-i+1 >= 3.

Now, in a recursive approach, at any position i, we can choose until position j, where j starts from i+2 and ends when distance of j from i becomes greater than 2*k (2*k as they will meet in middle position). Thus we need to iterate for each position, which leads to a complexity of O(n<sup>2</sup>).

To optimize this solution, we can think of an observation. Suppose we have man in position 1, 2, 3, 4, 5 & 6 and k = 2. we can take man from 1 to 5 in the same group as it satisfies the conditions. But man 6 is left alone. 
If we want to assign him in a group, the best choise can be to group upwith man 4 & 5 (we can probably take more, but not needed), if remaining members of 1st group (1, 2 & 3) forms a valid group. 
If there is also a man at 7 position and k = 2 remains. we only need to transfer the last person (at position 6) from first group to second group for a valid formation.
If there is also a man at 8 position and k = 2 remains, we don't need to transfer any man from first group to second group as we can make a valid group of man 6, 7 & 8.

From this observation, we can see that, we only needs three options from an starting postion, i. that is, if j is the last position within distance 2*k from i, then we can take **calc(i) = min(calc(j+1)+1, calc(j)+1, calc(j-1)+1)**. [for a group starting at position i]

Thus we have a complexity of O(n*logn) after memorization in dp array, where n for each possible starting position and logn for finding last valid position j for each valid position of longest distance with a binary search.

## Solution Code:

```c++
// . . . Bismillahir Rahmanir Rahim . . .
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int ara[N+5], dp[N+5];
int n, k;
const int inf = 1e9+7;

int calc(int at)
{
	if(at == n) return 0;
	if(at > n) return inf;

	if(dp[at] != -1) return dp[at];

	int val = ara[at] + 2*k;
	int i = upper_bound(ara, ara+n, val)-ara - 1;
	// cout << at << ' ' << i << '\n';

	if(i-at+1 < 3) return inf;

	int ans = inf;
	ans = min(ans, calc(i+1)+1);
	if(i-at >= 3) ans = min(ans, calc(i) + 1);
	if(i-at-1 >= 3) ans = min(ans, calc(i-1) + 1);

	return dp[at] = ans; 
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		cout << "Case " << cs << ": ";

		cin >> n >> k;

		for(int K = 0; K < n; K++) cin >> ara[K];

		sort(ara, ara+n);

		memset(dp, -1, sizeof dp);
		int ans = calc(0);

		cout << (ans == inf ? -1 : ans) << "\n";
	}

	return 0;
}
```