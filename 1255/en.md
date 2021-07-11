# Problem Name: Substring Frequency
## [LightOj-1255](https://lightoj.com/problem/substring-frequency)
## Discussion:
In this problem you are given two non-empty strings ` A ` and ` B `, both contain lower case English alphabets. You have to find the number of times ` B ` occurs as a substring of ` A `.<br>
**Note :** Count the number of times of ` B ` that occurs as a substring of ` A `.
## Solution Idea:
In naive approach,<br>
It checks for all character of the ` A ` to the ` B `. This algorithm is helpful for smaller texts.<br>It does not need any pre-processing phases. We can find substring by checking once for the string.<br>
The` time complexity of Naive Approach is ` **O(m*n)**.The ` m ` is the size of ` B ` and ` n ` is the size of the ` A `.<br>
But we can reduce this time complexity is **O(n+m)** using by **KMP(Knuth Morris Pratt) Pattern Searching**
If you don't know how KMP works then check out these sites.
* [KMP Algorithm](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)
* [KMP Algorithm -by Abdul Bari](https://www.youtube.com/watch?v=V5-7GzOfADQ)
Beautiful explanation of how the KMP string matching algorithm will work.

# CPP Code:
```cpp
#include <bits/stdc++.h>
using namespace std;

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char *pattern, int M, int *lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0;	// lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M)
	{
		if (pattern[i] == pattern[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else	// (pat[i] != pat[len])
		{
			if (len != 0)
			{
				len = lps[len - 1];

				// Also, note that we do not increment
				// i here
			}
			else	// if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int KMPSearch(char *pattern, char *txt)
{
	int M = strlen(pattern);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int lps[M];

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pattern, M, lps);

	int i = 0;	// index for txt[]
	int j = 0;	// index for pat[]
	int total = 0;
	while (i < N)
	{
		if (pattern[j] == txt[i])
		{
			j++;
			i++;
		}

		if (j == M)
		{
			total++;
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pattern[j] != txt[i])
		{
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}

	return total;
}

int main()
{
	int test;
	cin >> test;
	char txt[1000001], pattern[1000001];
	for (int t = 1; t <= test; t++)
	{
		cin >> txt >> pattern;
		int total = KMPSearch(pattern, txt);
		cout << "Case " << t << ": " << total << '\n';

	}
}

```

Happy Coding!!

Written by:[Md. Rasel Meya](https://www.linkedin.com/in/raselmeya/)
