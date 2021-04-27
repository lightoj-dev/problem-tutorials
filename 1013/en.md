# LOJ 1013 - Love Calculator
---
Tags : String, Subsequence, Dynamic Programming, Memoization, Knapsack

We need to find some __shortest _possible_ Strings__ _possible_ (meaning that they won't have any unnecessary __suffix__ or __prefix__) that can produce the names as __Subsequences__ and we have to output :

1. How many __unique Strings__ are there?
2. What is the __length__?

### Helpful Resources
* [Substring - WikiPedia](https://en.wikipedia.org/wiki/Substring "WikiPedia")

* [Subsequence - WikiPedia](https://en.wikipedia.org/wiki/Subsequence "WikiPedia")

* [Subarray/Substring vs Subsequence and Programs to Generate them - GeeksForGeeks](https://www.geeksforgeeks.org/subarraysubstring-vs-subsequence-and-programs-to-generate-them/)

* [Memoization - WikiPedia](https://en.wikipedia.org/wiki/Memoization "Memoization - WikiPedia")

* [Memoization (1D, 2D and 3D) - GeeksForGeeks](https://www.geeksforgeeks.org/memoization-1d-2d-and-3d/ "Memoization (1D, 2D and 3D)")

* [What is Dynamic Programming ? - educative.io](https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews/m2G1pAq0OO0 "[What is Dynamic Programming?")

* [Dynamic Programming, Memoization, Tabulation - freeCodeCamp.org  (Video)](https://www.youtube.com/watch?v=oBt53YbR9Kk "FreeCodeCamp - YouTube")

## Solution
The problem statement has already mentioned that the __length__ of the __names (Strings)__ will not cross __30__. We will take two __2D arrays__ of size `31 x 31` (although we just need `length of name1 * length of name2` for each test case but let's keep it this way just for the sake of ease of implementation and since neither it consumes a lot of memory), one for _memoizing_ the length of the __shortest String__ and another one to keep record of how many __unique Strings__ are generated.

But first let us understand what type of __Strings__ we are counting and to do that let's take an example:
```
USA
USSR
```
For the above example (and others), __all__ (meaning that they may contain _unnecessary_ __suffix__ and __prefix__) the possible __Strings__ whose __Subsequences__ can produce both the name is actually __inifinite__. For example:
```
USSRA
abcdUSSRApzxockbvbkpvzxco
USASRadasdasd
USSAR
fwetUSSARrweUSASRadasdasd
dasdsadasdsadcwqrfqtgUSASR
gjoUSSRApidhUSSARglkdfg
dfgdgfUSSAR
USSARgnsdihgisgf
...
...

```
But the problem has asked us to find the __shortest Strings__ whose __Subsequences__ can produce __both__ of the names. So we __don't__ keep any unnecessary __suffix__ or __prefix__.
For distinction only and to make them easily detectable, some __Substrings__ are capitalized in each __Strings__ shown above, from which we can obtain both `USA` and `USSR`.

For example :
From the __String__ `fwetUSSARrweUSASRadasdasd`, we can take __any__ of the __Substrings__ `USSAR` __or__ `USASR` which _both of them_ can produce the __Subsequences__ `USA` and `USSR`. Remember that __both__ the __Substrings__ and __Subsequences__ must maintain __order of characters__ of its original __String__. The only __difference__ between __Substrings__ and __Subsequences__ is that __Substrings__ must contain __consecutive characters__ too while __Subsequences__ has __NO__ such bound.

Now if we just think of __shortest Strings__ for this particular test case, those would be only these 3 :
```
USSRA
USSAR
USASR
```
And as already mentioned before, `RAUSS` or similar __Strings__ that contain all the __characters__ of both the names but if the __characters__ to produce the names can __NOT__ be retrieved in a __Sequential order__, are not __Subsequences__ at all, thus we are not counting them nor they are our concern.


Now that we have finally understand what type of __Strings__ we are looking for, let's understand how we are using the arrays to _memoize_ and find the solutions.

At first we will take the names and shift their characters right by 1 index for ease of comparison and implementation in the upcoming steps.

As we have shifted the __characters__ to right by 1 index, then we simply create both the matrix for _dynamic programming_ by occupying the __first column__ and __first row__.

For the __shortest Strings__ matrix, we will put the max  co-ordinate value to each of blocks in 1st column and 1st row. For example: for `(4,0)` and `(0,4)`, `4` is the maximum of both the values so those two blocks will have `4` as their value.

The `shortestString` matrix should look like something like this :

|I/J|0   |1   |2   |3   |4   |...   |30   |
|:-:|---|---|---|---|---|---|---|
|__0__   | 0  |1   | 2  |3   |4   |...   |30   |
| __1__  |  1 |   |   |   |   |   |   |
|  __2__ |   2|   |   |   |   |   |   |
|   __3__|   3|   |   |   |   |   |   |
|   __4__|   4|   |   |   |   |   |   |
|__...__|   ...|   |   |   |   |   |   |
|__30__|   30|   |   |   |   |   |   |

Now to _memoize_ the __shortest String__ matrix, we must check the __characters__ of a __name__ in respect to the other one. We just simply keep adding `1` to the _last updated_ __cumulative sum__. For example : if `name1[2]` and `name2[3]` matches, so for `shortestString[2,3]` , the recent last __cumulative sum__ can be taken from it's __upper left block `shortestString[1,2]`__ and we will just add `1` to it. And if the __characters__ _don't_ match, we get the __cumulative sum__ from `shortestString[2,2]` or `shortestString[1,3]` depending on which is the __minimum__ among them and add `1` to it.
In example of `USA` and `USSR`, it will look something like this after _memoization_.

|i/j   |0   |1(U)   |2(S)   |3(S)   |4(R)   |
|:-:|---|---|---|---|---|
|  __0__ |0   |1   |2   |3   |4   |
|   __1(U)__|  1 |1(U)   |2(US)   |3(USS)   |4(USSR)   |
|   __2(S)__|  2 |2(US)   |2(US)   |3(USS)   |4(USSR)   |
|   __3(A)__|   3|3(USA)   |  3(USA) | 4<br> (USA + S)<br>[from j=3]<br> / (USS + A)from[i=3]<br>=(USAS/USSA)   |__5__<br>((USAS/USSA) + R))<br>/(USSR + A)<br> =(USASR/USSAR/USSRA)   |

And `shortestString[name1.length()-1][name2.length()-1]` give us the __length of the shortest string__ which is `5`.

For the __unique String__ matrix, we occupy the 1st column and 1st row with `1`s because we are assuming that the number of __unique string__ is `1`, simply `name1 = name2` meaning there is no __difference of characters__.

The `uniqueString` matrix should look like this initially:

|I/J|0   |1   |2   |3   |4   |...   |30   |
|:-:|---|---|---|---|---|---|---|
|__0__   | 1  |1   | 1  |1   |1   |...   |1   |
| __1__  |  1 |   |   |   |   |   |   |
|  __2__ |   1|   |   |   |   |   |   |
|   __3__|   1|   |   |   |   |   |   |
|   __4__|   1|   |   |   |   |   |   |
|__...__|   ...|   |   |   |   |   |   |
|__30__|   1|   |   |   |   |   |   |


When the __characters__ matches, we don't need to create/branch out to another __String__ and thus we simply just update the value of the current block by taking the __number of unique string__ from __upper-left block__.

When there's a __difference of character__, then we will know that we need to branch out, meaning another unique sequence might be initiated. In such case we will take help from the `shortestString` matrix because while memoizing it, we actually saved information such as how many different characters were  at which point.

When `shortestString` matrix's `left` and `upper` block hold the same value, it means that there had been __2 unique strings__ of the  __same length__ as we can already see in the `shortestString` matrix. So we simply count __both__ of them by __summing__ how many __unique strings__ were encountered before we updated those 2. An example already is given in case of `shortestString[3][3]` and `shortestString[3][4]` in the table for `shortestString` matrix. That's why `uniqueString[3][3] = uniqueString[3][2] + uniqueString[2][3]`. Same applied to `uniqueString[3][4]`.

In any other case where `shortestString[i][j-1] != shortestString[i-1][j]`, we __first__ evaluate the __minimum__ between `shortestString[i][j-1]`and `shortestString[i-1][j]`. __After that__ in correspondence to __shortest String matrix's compared minimum block's [row][column]__, we take  value of `uniqueString[row][column]` and put into the __current unique String matrix's block__.

If we have done everything accordingly, `uniqueString` matrix should look like this :

|i/j   |0   |1   |2   |3   |4   |
|:-:|---|---|---|---|---|
|  __0__ |1   |1   |1   |1   |1   |
|   __1__|  1   |1   |1   |1   |1   |
|   __2__|  1   |1   |1   |1   |1   |
|   __3__|   1   |1   |1   |2   |__3__   |

Now, `uniqueString[name1.length()-1][name2.length()-1]` tells us how many __unique Strings__ are there.

The above implementation is `accepted`.

Caution : The matrix to memoize the number of __unique strings__, must be of an integer data type that can hold 2<sup>63</sup>.

Notes :
* You can solve the problem _recursively_ too and it won't throw any TLE.
* `long` data type's size of `c++` is dependent on the hardware (processor) and the software (operating system and compiler). LightOJ uses a __64-bit__ compiler so only `long` is sufficient. However we might need to use `long long` if any of the dependency is __32-bit__.

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

        //Prepare the matrices for memoization
        for (int i = 0; i < 31; i++)
            shortestString[0][i] = shortestString[i][0] = i, uniqueString[i][0] = uniqueString[0][i] = 1;

        for (int i = 1; name1[i]; i++)
        {
            for (int j = 1; name2[j]; j++)
            {
                //Checking if we need to take the cumulative sum from upper-left block
                if (name1[i] == name2[j])
                {
                    shortestString[i][j] = 1 + shortestString[i - 1][j - 1];

                    //no need to add a new branch so taking cumulative sum from upper-left block
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
