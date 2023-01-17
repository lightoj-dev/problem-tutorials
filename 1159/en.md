
# [LOJ 1159 Batman](https://lightoj.com/problem/batman)

## Solution Approach:
In this problem given 3 string and need to find the length of the longest common subsequence 
[LCS](https://www.programiz.com/dsa/longest-common-subsequence) of these three strings.

Its not necessary that the characters have to be next to each other 
in the original strings.

One approach to solve the problem is to create a 3-dimensional table with dimensions corresponding
to the lengths of each of the three input strings.
The sub-problems in this case are the substrings 
dp[1...i], Y[1...j], Z[1...k] for all possible values of i, j, k

To compute the value of LCS[i][j][k], we consider three possibilities:
- You can start by checking base case whether the length of any string is 0, in which case the LCS is 0.
- if three characters match, length of the common subsequence would be 1 plus 
  the length of the common subsequence till the i-1,j-1 and k-1 indexes
- Otherwise, the LCS is will be maximum of value of the element above or to the left of the 
  current element of three strings(max of neighbour elements).

The final LCS value is stored in LCS[m][n][o], which is the LCS of the three input strings.

This question is similar to [this question](https://leetcode.com/problems/longest-common-subsequence/description/), you can check that also.


# C++
```
#include<bits/stdc++.h>
using namespace std;


int LCS( string X, string Y, string Z, int m, int n, int o)
{
	int dp[m+1][n+1][o+1];

//Going with bottom up aproach
	for (int i=0; i<=m; i++)
	{
		for (int j=0; j<=n; j++)
		{
			for (int k=0; k<=o; k++)
			{
				if (i == 0 || j == 0||k==0)
					dp[i][j][k] = 0;

				else if (X[i-1] == Y[j-1] && X[i-1]==Z[k-1])
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;

				else
					dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
			}
		}
	}

	
	return dp[m][n][o];
}


int main()
{

    int len;
    cin>>len;
    for(int idx=1;idx<=len;idx++){
       string X,Y,Z;
       cin>>X>>Y>>Z;

	

	int m = X.length();
	int n = Y.length();
	int o = Z.length();

	cout << "Case "<< idx<<": "<< LCS(X, Y,Z, m, n, o)<<endl;

	
}
}
```
