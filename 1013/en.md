# LOJ 1013 - Love Calculator
---
Tags : String, Subsequence, Dynamic Programming, Memoization

We need to find some __shortest _possible_ Strings__(meaning that they won't have any unnecessary __suffix__ or __prefix__) that can produce the names as __Subsequences__ and we have to output :

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

The problem statement has already mentioned that the _length_ of the _names (Strings)_ will not cross __30__. We will take two __2D arrays__ of size `31 x 31` (although we just need _length of name1 * length of name2_ for each test case but let's keep it this way just for the sake of ease of implementation and since neither it consumes a lot of memory),
* one for _memoizing_ the length of the _shortest String_
* another one to keep record of how many _unique Strings_ are generated.

But first let us understand what type of __Strings__ we are counting and to do that let's take an example:
```
USA
USSR
```
For the above example (and others), _all_ (meaning that they may contain _unnecessary_ _suffix_ and _prefix_) the possible __Strings__ whose _Subsequences_ can produce both the name is actually __inifinite__. For example:
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
But the problem has asked us to find the __shortest Strings__ whose __Subsequences__ can produce _both_ of the names. So we _don't_ keep any unnecessary _suffix_ or _prefix_.
For distinction only and to make them easily detectable, some _Substrings_ are capitalized in each _Strings_ shown above, from which we can obtain both `USA` and `USSR`.

For example :
From the _String_ `fwetUSSARrweUSASRadasdasd`, we can take _any_ of the _Substrings_ `USSAR` or `USASR` which _both of them_ can produce the _Subsequences_ `USA` and `USSR`. Remember that _both_ the _Substrings_ and _Subsequences_ must maintain the _order of characters_ of its original _String_. The only difference between _Substrings_ and _Subsequences_ is that _Substrings_ must contain _consecutive characters_ too while _Subsequences_ has NO such bound.

Now if we just think of _shortest unique Strings_ for this particular test case, those would be only these 3 :
```
USSRA
USSAR
USASR
```
And as already explained before, `RAUSS` or similar _Strings_ that contain all the _characters_ of both the names but if the _characters_ to produce the names can __NOT__ be retrieved in a _Sequential order_, are not _Subsequences_ at all, thus we are not counting them nor they are our concern.


Now that we have finally understand what type of __Strings__ we are looking for, let's understand how we are using the arrays to _memoize_ and find the solutions.

#### How are we keeping track of common characters (shortest length of the substring)?

At first we will take the names and shift their characters right by 1 index for ease of comparison and implementation in the upcoming steps. Also because at `length  == 0` they won't have any common characters at all.
As we have shifted the __characters__ to right by 1 index, then we simply create both the matrix for _dynamic programming_ by occupying the __first column__ and __first row__. We can we do it in any fashion we want. _Row_ and _Column_ represents the characters of each of names. I have chosen _Row_ to represent the first name and the _Column_ to represent the second name, it can be done other way around as well.  

For the __shortest Strings__ matrix, we will put the `max(row,column)` value to each of blocks in j-th column and i-th row. For example: for `(4,0)` and `(0,4)`, `4` is the maximum of both the values so those two blocks will have `4` as their value. We are doing this because we are assuming `name1 == name2` at the initial stage.

The `shortestString` matrix should look like something like this at the _initial state_:

|I/J|0   |1   |2   |3   |4   |...   |30   |
|:-:|---|---|---|---|---|---|---|
|__0__   | 0  |1   | 2  |3   |4   |...   |30   |
| __1__  |  1 |   |   |   |   |   |   |
|  __2__ |   2|   |   |   |   |   |   |
|   __3__|   3|   |   |   |   |   |   |
|   __4__|   4|   |   |   |   |   |   |
|__...__|   ...|   |   |   |   |   |   |
|__30__|   30|   |   |   |   |   |   |


Now to _memoize_ the _shortestString_ matrix, we must check the _characters_ of a __name__ in respect to the other one. Each `block` represents the common length of the shortest string required for both of the names' 1st character to those particular `indice` of those names respectively. (__Remember__, we already shifted the characters by `1` character.)

For Example : `shortestString[1][3]`'s `value` is the length required when I am taking name1's to substring length = 1  (`USA`'s length 1 substring == "`U`") and name2's substring length = 3 (`USSR`'s length 3 substring == "`USS`"). So, `shortestString[1][3]` = `3` is required as the bare minimum length for `U` and `USS`.

|i/j   |0   |1(U)   |2(S)   |3(S)   |
|:-:|---|---|---|---|
|  __0__ |0   |1   |2   |3   |4   |
|   __1(U)__|  1 |1(U)   |2(US)   |3(USS)



We just simply keep adding `1` to the last updated _cumulative sum_. Let's understand what to do on which condition :
* __Case name1[i] == name2[j] :__ Since both of the `characters` are same, we don't need to extend the string length. We can just add `1` to previous common length from upper-left block, which is `shortestString[i-1][j-1]`. Look at the table below for clarification of an example:
  * Example :

    i[2]  == j[3]

    For "US" of "USA" (since i == 2) and "USS" of "USSR" (since j == 3)

    So,
    ```
    shortestString[2][3]
    = shortestString[2-1][3-1] + 1
    = 2 + 1 = 3
    ```



* __Case name1[i] != name2[j] :__ Since the `characters` don't match, we will take the __minimum__ (look at example to understand why __not__ maximum) length encountered between `first name`'s length and `second name`'s length. For clarification let us again look at the table with an example:

  * Example :

    i[1] != j[2]

    So,
    ```
    shortestString[2][3]
    = min(shortestString[2][2],shortestString[1][3]) + 1
    = shortestString[2][2] + 1 = 3

    ```
    if we had taken maximum then it had been
    ```
    shortestString[2][3]
    = shortestString[1][3] + 1 = 4
    ```
    But do we really need `USSS` to get name1's `2` length substring `US` and name2's `3` length substring `USS`? In other words, by taking maximum we are actually considering `US` and `USSS` which is because `USS` is already included in `shortestString[1][3]`; thus unnecessary suffix has been added.

In example of `USA` and `USSR`, it will look something like this after _memoization_.

|i/j   |0   |1(U)   |2(S)   |3(S)   |4(R)   |
|:-:|---|---|---|---|---|
|  __0__ |0   |1   |2   |3   |4   |
|   __1(U)__|  1 |1(U)   |2(US)   |3(USS)   |4(USSR)   |
|   __2(S)__|  2 |2(US)   |2(US)   |3(USS)   |4(USSR)   |
|   __3(A)__|   3|3(USA)   |  3(USA) | 4<br> (USA + S)<br>[from j=3]<br> / (USS + A)from[i=3]<br>=(USAS/USSA)   |__5__<br>((USAS/USSA) + R))<br>/(USSR + A)<br> =(USASR/USSAR/USSRA)   |

And `shortestString[name1.length()-1][name2.length()-1]` give us the __length of the shortest string__ which is `5`.

#### How are we keeping track of unique strings?

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

While populating there can be these cases :
* __Case name1[i] == name2[j] :__ When the __characters__ matches, we don't need to create/branch out to another new sequence and thus we simply just update the value of the current block by taking the _number of unique string_ from _upper-left block_.

* __Case name1[i] != name2[j] && shortestString[i][j - 1] == shortestString[i - 1][j] :__ It means there had been _2 unique strings sequence_ of the  __same length__ as we can already see in the `shortestString` matrix. And we need to take both the sequence in account.
  * Example :

      `shortestString[3][3]` is populated by this way. How? name1 length 3 substring is `USA` and name2 length 3 substring is `USS`. `shortestString[2][3]` is `USS` and `shortestString[3][2]` is `USA` and neither of them can produce the other name's substring upto that length. So we can add the unique sequence character `A` of name1 to name2's length 3 substring `USS+A`; also if we do it the other way around, add the unique sequence character `S` of name2 to name1's length 3 substring `USA+S`, is valid and has to be counted as per question requirement. So, we are adding the number of unique strings found in those states.
      ```
      shortestString[3][3]
      = number of unique strings found for name1 length 3 substring
      + number of unique strings found for name2 length 3 substring
      = shortestString[3][2] + shortestString[2][3] = 2

      ```

* __Case name1[i] != name2[j] && shortestString[i][j - 1] != shortestString[i - 1][j] :__ In this case we just simply take the minimum of which can be taken from left block or upper block. The logic is similar to `shortestString[][]` population. We don't want unnecessary suffix to be added.


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
* You can solve the problem _recursively_ too and it won't throw any MLE.
* `long` data type's size of `c++` is dependent on the hardware (processor) and the software (operating system and compiler). `LightOJ` uses a __64-bit__ compiler so only `long` is sufficient. However we might need to use `long long` if any of the dependency is __32-bit__.

## Solution in C++ (Iterative)
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
                    //Adding 1 to cumulative sum from upper-left block
                    shortestString[i][j] = 1 + shortestString[i - 1][j - 1];

                    //No need to add a new branch of unique strings so taking cumulative sum from upper-left block
                    uniqueString[i][j] = uniqueString[i - 1][j - 1];

                }
                else
                {
                    //Finding the minimum from left and upper block and adding 1 to the value of current block
                    shortestString[i][j] = 1 + min(shortestString[i][j - 1], shortestString[i - 1][j]);

                    //Checking if there are two unique strings of the same length
                    if (shortestString[i][j - 1] == shortestString[i - 1][j])
                        uniqueString[i][j] = uniqueString[i][j - 1] + uniqueString[i - 1][j];

                        //Checking if left block has the minimum value in shortestString matrix
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


## Solution in C++ (Recursive)
```cpp
#include <bits/stdc++.h>

using namespace std;

string name1, name2;
int shortestString[31][31];
long uniqueString[31][31];

void memoizeArrays(int i, int j){
    if(i == name1.length()) //base case
        return;

    if(j == name2.length()) //check next row and set column to 1
        return memoizeArrays(++i, 1);

    else{
        if (name1[i] == name2[j]){

          //Adding 1 to cumulative sum from upper-left block/current common length of both string
          shortestString[i][j] = 1 + shortestString[i - 1][j - 1];

          //No need to add a new branch of unique strings so taking cumulative sum from upper-left block
          uniqueString[i][j] = uniqueString[i - 1][j - 1];
        }else{

          //Finding the minimum from left and upper block and adding 1 to the value of current block
            shortestString[i][j] = 1 + min(shortestString[i][j - 1], shortestString[i - 1][j]);

          //Checking if there are two unique strings of the same length
            if (shortestString[i][j - 1] == shortestString[i - 1][j])
                uniqueString[i][j] = uniqueString[i][j - 1] + uniqueString[i - 1][j];
              //Checking if left block has the minimum value in shortestString matrix
            else if (shortestString[i][j - 1] < shortestString[i - 1][j])
                uniqueString[i][j] = uniqueString[i][j - 1];
            else
                uniqueString[i][j] = uniqueString[i - 1][j];
        }

        //Check next column of the same row
        return memoizeArrays(i, ++j);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;

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

        //Memoize the array
        memoizeArrays(1, 1); //Remember, we shifted characters to the right by 1 character
        cout << "Case " << testCase << ": " << shortestString[name1.length() - 1][name2.length() - 1] << " " << uniqueString[name1.length() - 1][name2.length() - 1] << "\n";
    }
    return 0;
}

```
