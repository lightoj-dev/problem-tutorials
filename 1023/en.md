# Problem Name: Discovering Permutations
## [LightOj-1023](https://lightoj.com/problem/discovering-permutations)
## Problem Summary:
You are given two integer numbers which are N and K.
Here, N denoted by the first N English capital letters and K denote by the number of permutations.
If the number of all permutations is less than K then print all of them.

## prerequisite:
 * [Recurssion](https://www.geeksforgeeks.org/recursion/)
 * [STL (next_permutation)](https://www.geeksforgeeks.org/stdnext_permutation-prev_permutation-c/)

## Idea and Solution:
At first, Observe the process on how to work the `next_permutation` method in this code.<br>
Let, take a string `X=" ABCDEF"` and it's already lexicographically sorted by ascending order.<br>
The following algorithm generates the next permutation lexicographically after a given permutation.that's means `next_permutation`function return the next immediate larger permutation than the current permutation.
It changes the given permutation in-place.<br>
some permutation order:<br>
ABCDEF<br>
ABCDFE<br>
ABCEDF<br>
ABCEFD<br>
...<br>
FEDCBA<br>

**Time Complexity: O(n*n!)** per test_case<br>

## STL Code:
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test_case;
	cin >> test_case;
	string all = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int t = 1; t <= test_case; t++)
	{
		int N, K;
		cin >> N >> K;
		string x, check;
		x = all.substr(0, N);
		check = x;
		cout << "Case " << t << ":" << '\n';
		for (int i = 1; i <= K; i++)
		{
			cout << x << '\n';
			next_permutation(x.begin(), x.end());
			if (x == check) break;
		}
	}

	return 0;
}
```
Happy Coding!

Written by: [Md. Rasel Meya](https://lightoj.com/user/rhrasel94)
