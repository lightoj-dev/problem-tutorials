# LightOJ 1393 - Crazy Calendar

_Keywords: Nim_

In a R x C grid, there're some coins. Two player are playing a game. In each move,
the current player can choose a non-empty cell (which is not (R, C)) and move some
coins to the right cell or down. The player who can't make a move loses.

### Solution

For a cell (x, y), we can think of this as a pillar of height `R-x + C-y` and the
coins in that cell as a pile of stones on that piller. Moving some coins to the
cell right or beneath it is equivalent to moving some stones from this pillar of
height `h` to a pillar of `h-1`. This is indeed a classic example of
_Staircase Nim_, a lesser known Nim game, for which _Shafaet Ashraf_ has written
[a brilliant blog post on CodeForces](https://codeforces.com/blog/entry/44651).

You may also look [at this answer in StackExchange](https://math.stackexchange.com/a/2216940)
for a better understanding.

So, we shall compute the xor-sum of the pile-sizes for those pillars who have odd
heights. And if xor-sum is non-zero, first player wins. Otherwise, (s)he loses.

### C++ Code:

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, tc=0;
	scanf("%d", &t);

	while(t--) {
		int r, c;
		scanf("%d %d", &r, &c);

		int xorsum = 0;

		for(int i=1; i<=r; ++i) {
			for(int j=1; j<=c; ++j) {
				int x;
				scanf("%d", &x);

				int d = r-i + c-j;
				if(d % 2) xorsum ^= x;
			}
		}

		printf("Case %d: %s\n", ++tc, (xorsum ? "win" : "lose"));
	}

	return 0;
}
```

---

_[reborn++](https://lightoj.com/user/rebornplusplus)_ <br/>
_Jun 22, 2021_
