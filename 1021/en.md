# LOJ 1021 - Painful Bases

---

Input starts with an integer _T_ (≤ 100), denoting the number of test cases.
Each case has 3 inputs namely base of the number, and the number k, through which we have to check divisibility and lastly a string of character representing the number.Also the question states that leading zeroes in permutation is allowed.

It is given that all characters are distinct, so maximum characters can be 16, and to solve this problem we will use bitmask and DP.

```
for all i such that i is not set in mask:
       dp[mask | (1 << i)][(rem * base + digit[i]) % k] += dp[mask][rem]
```

where `dp[mask][rem]` reprensents, the the number of permutations possible now that some digits are already fixed and a remainder `rem` (after dividing by `k`) is achieved so far; the fixed digits have corresponding bits set in `mask`.

Now the question is how we reached the dp states, if we have currently remainder **rem** and we add digit **dig** in last then the effective number will be _(rem\*base)+dig_ and again we take remainder by k, and also update mask.

It is worth noting that `dp[mask = 0][rem = 0] = 1`.

This question is similar to [this question](https://codeforces.com/problemset/problem/401/D), you can check that also, and if you are facing how dp reduced time check [this](https://codeforces.com/blog/entry/20076) and [this](https://codeforces.com/blog/entry/19423) link.

## Solution in C++

```cpp
// Author: masked_huh
// Created: 2021-04-12 23:08:14

/*Success isn't permanent, failure isn't fatal,
it's the courage to continue that counts.*/

#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;

int getdigit(char c)
{
	if('0' <= c && c <= '9')
		return int(c -'0');

	return int(c -'A') +10;
}

ll dp[(1<<17)][21];

void solve()
{
	int base,k;
	cin>>base>>k;

	string str;
	cin>>str;

	int len=str.length();
	int compmask=(1<<len)-1;

	memset(dp,0,sizeof(dp));

	dp[0][0]=1;

	for(int mask=0;mask<(1<<len);mask++)
	{
		for(int idx=0;idx<len;idx++)
		{
			if(mask&(1<<idx))
				continue;
			for(int rem=0;rem<k;rem++)
			{
				int dig=getdigit(str[idx]);
				dp[mask|(1<<idx)][(rem*base+dig)%k]+=dp[mask][rem];
			}
		}
	}

	cout<<dp[compmask][0]<<endl;

	return;
}

int main()
{
	fast;

	int t=1;
	cin>>t;

	for(int i=1;i<t+1;i++)
	{
		cout<<"Case "<<i<<": ";
		solve();
	}

    return 0;
}

```
