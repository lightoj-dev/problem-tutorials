# LOJ 1186 - Incredible Chess

### Summary

This game is played on an $n*n$ board. In each column there are two pawns, the higher one belongs to Alice, and the lower one belongs to Bob. Every pawns could go forward or backward any positive integer steps, but it couldn't jump over any piece in each move. The game ends when there is no move for a player and he/she will lose the game.

### Solution

#### Hint 1

For each column, when a player goes backward $k$ steps, the other player only needs to go forward $k$ steps to keep the state unchanged. So we just need to consider the space between the two pawns in each column.

#### Hint 2

If we only need to consider the space between the two pawns in each column, we can think of the distance between the two pawns as stones, with each move taking some stone. Then this is just a Nim game.

So we only need to determine whether the $xor sum$ of the distances of all the columns is $0$.

### Code

##### C++

```cpp
#include <bits/stdc++.h>
using namespace std;

int t,n;
int w[105],b[105];

int main()
{
	scanf("%d",&t);
	for(int times=1;times<=t;times++)
	{
		int xorSum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&w[i]);
		for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            xorSum^=(b[i]-w[i]-1);
        }

		if(xorSum==0) printf("Case %d: black wins\n",times);
		else printf("Case %d: white wins\n",times);
	}
}
```

