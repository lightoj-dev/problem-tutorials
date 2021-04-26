# LOJ 1013 - Love Calculator
---
Tags : String, Subsequence, Dynamic Programming, Memoization,


### Helpful Resources
* [Substring - WikiPedia](https://en.wikipedia.org/wiki/Substring "WikiPedia")

* [Subsequence - WikiPedia](https://en.wikipedia.org/wiki/Subsequence "WikiPedia")

* [Subarray/Substring vs Subsequence and Programs to Generate them - GeeksForGeeks](https://www.geeksforgeeks.org/subarraysubstring-vs-subsequence-and-programs-to-generate-them/)

* [Memoization - WikiPedia](https://en.wikipedia.org/wiki/Memoization "Memoization - WikiPedia")

* [Memoization (1D, 2D and 3D) - GeeksForGeeks](https://www.geeksforgeeks.org/memoization-1d-2d-and-3d/ "Memoization (1D, 2D and 3D)")

* [What is Dynamic Programming ? - educative.io](https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews/m2G1pAq0OO0 "[What is Dynamic Programming?")

* [Dynamic Programming, Memoization, Tabulation - freeCodeCamp.org  (Video)](https://www.youtube.com/watch?v=oBt53YbR9Kk "FreeCodeCamp - YouTube")

## Solution
The given problem has already mentioned that the __length__ of the __Strings__ will not cross __30__. We will take two __2D arrays__ of size `31 x 31` (although we just need `length of name1 * length of name2` for each test case but let's keep it this way just for the sake of ease of implementation and since neither it consumes a lot of memory), one for _memoizing_ the length of the __shortest String__ that contains both the names and another one to keep record of how many __unique Strings__ are encountered that contain names as __Subsequences__.

But first let us understand what type of __Strings__ we are counting and to do that let's take an example:
```
USA
USSR
```
For the above example, __all__ the possible __Strings__ whose __Subsequences__ can produce both the name is actually __inifinite__. For example:
```
abcdUSSRApzxockbvbkpvzxco
USASRadasdasd
fwetUSSARrweUSASRadasdasd
dasdsadasdsadcwqrfqtgUSASR
gjoUSSRApidhUSSARglkdfg
dfgdgfUSSAR
USSARgnsdihgisgf
...
...

```
And thus the problem has asked us to find the __shortest Strings__ whose __Subsequences__ can produce __both__ of the names.
For distinction only and to make them easily detectable, some __Substrings__ are capitalized from each __String__, from which we can obtain both `USA` and `USSR`.

For example :
From the __String__ `fwetUSSARrweUSASRadasdasd`, we can take __any__ of the __Substrings__ `USSAR` __or__ `USASR` which _both of them_ can produce the __Subsequences__ `USA` and `USSR`. Remember that __both__ the __Substrings__ and __Subsequences__ must maintain __order of characters__ of its original __String__. The only _difference_ between __Substring__ and __Subsequences__ is that __Substrings__ must contain __consecutive__ letters too while __Subsequences__ has __NO__ such bound.

Now if we just think of __shortest Strings__ for this particular test case, those would be only these 3 :
```
USSRA
USSAR
USASR
```
And as already mentioned before, `RAUSS` or similar __Strings__ that contain the __letters__ of names but the __letters__ to produce the names can __NOT__ be retrieved in a __Sequential order__ are not __Subsequences__ at all, thus we are not counting them nor they are our concern.


Now that we have finally understand what type of __Strings__ we are looking for, let's understand how we are using the arrays to _memoize_ the solution.

At first we will take the names and shift their characters right by 1 index for ease of comparison and implementation in the upcoming steps.

For the array to count the __shrotest Strings__

## Solution in C++
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    string name1, name2;

    int shortestString[31][31];
    long uniqueString[31][31];

    cin >> testCases;

    for (int testCase = 1; testCase <= testCases; testCase++)
    {
        cin >> name1 >> name2;
        //Shift the characters of the name to right for ease of memoizing
        name1.insert(0, "0");
        name2.insert(0, "1");

        for (int i = 0; i < 31; i++)
            shortestString[0][i] = shortestString[i][0] = i, uniqueString[i][0] = uniqueString[0][i] = 1;

        for (int i = 1; name1[i]; i++)
        {
            for (int j = 1; name2[j]; j++)
            {
                if (name1[i] == name2[j])
                {
                    shortestString[i][j] = 1 + shortestString[i - 1][j - 1];
                    uniqueString[i][j] = uniqueString[i - 1][j - 1];
                }
                else
                {
                    shortestString[i][j] = 1 + min(shortestString[i][j - 1], shortestString[i - 1][j]);
                    if (shortestString[i][j - 1] == shortestString[i - 1][j])
                        uniqueString[i][j] = uniqueString[i][j - 1] + uniqueString[i - 1][j];
                    else if (shortestString[i][j - 1] < shortestString[i - 1][j])
                        uniqueString[i][j] = uniqueString[i][j - 1];
                    else
                        uniqueString[i][j] = uniqueString[i - 1][j];
                }
            }
        }
        cout << "Case " << testCase << ": " << shortestString[name1.length() - 1][name2.length() - 1] << " " << uniqueString[name1.length() - 1][name2.length() - 1] << "\n";
    }
    return 0;
}

```
