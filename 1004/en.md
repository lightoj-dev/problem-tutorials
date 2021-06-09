# LOJ 1004 - Monkey Banana Problem
---
Tags : Dynamic Programming, Memoization

We will be given a __diamond__ shaped array's __number of columns__, the monkey can climb down _only_ to __any of 2 adjacent blocks below__, which can also be _interpreted_ as, a block can be updated by summing __max value found among the 2 adjacent blocks from upper row__. We have to find out the maximum amount of Banana it can consume when he reaches the last block. In other words, we have to find out the maximum cumulative sum can be obtained by traversing in the above mentioned way

### Helpful Resources

* [Memoization - WikiPedia](https://en.wikipedia.org/wiki/Memoization "Memoization - WikiPedia")

* [Memoization (1D, 2D and 3D) - GeeksForGeeks](https://www.geeksforgeeks.org/memoization-1d-2d-and-3d/ "Memoization (1D, 2D and 3D)")

* [What is Dynamic Programming ? - educative.io](https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews/m2G1pAq0OO0 "[What is Dynamic Programming?")

* [Dynamic Programming, Memoization, Tabulation - freeCodeCamp.org
 (Video)](https://www.youtube.com/watch?v=oBt53YbR9Kk "FreeCodeCamp - YouTube")

## Solution

To solve this we must construct a _matrix_ (array/linked list/any similar data structure) to take inputs. We can take inputs in any preferred _indexing_ as long as we can easily determine by ourselves __which 2 blocks are adjacent from upper row for a particular block__.
For example:

| R/C  | 0 | 1 | 2  | 3  |
|---|---|---|----|----|
| __0__ | 7 |0|0 |0 |
| __1__ | 6 | 4 |0 |0 |
| __2__ | 2 | 5 | 10 |0 |
| __3__ | 9 | 8 | 12 | 2  |
| __4__ |0| 2 | 12 | 7  |
| __5__ |0|0| 8  | 2  |
| __6__ |0|0|0 | 10 |

Here in this kind of indexing, the __2 adjacent blocks__ from __upper row__ for block __B<sub>R C</sub>__ is, __B<sub>(R-1) C</sub>__ & __B<sub>(R-1) (C-1)</sub>__ (i.e.: block<sub>2 1</sub>'s adjacent blocks from upper row are block<sub>1 1</sub> and block<sub>1 0</sub> where block<sub>2 0</sub> has only block<sub>1 0</sub> ).  __Remember, we need to avoid negative index__.

We will take another matrix of the same dimension to store the _max possible value can be reached for each particular block_. Now we just simply start updating the values for each block from its upper row and ultimately will obtain the max possible value for __end block__.
```
In our implementation,

adjacent blocks from upper row for block[row][column]
= { block[row-1][column], block[row-1][column-1] }
* for block[row][0], adjacent block = block[row-1][0] only

maxBanana[row][column]
= ( maximum( block[row-1][column], block[row-1][column-1] ) )
+ actualBanaMatrix[row][column]
```
| Block(R,C) | Cumulative Banana (B[R-1][C-1]) | Cumulative Banana (B[R-1][C]) | Max among Cumulative Bananas (Upper Row)  |Actual Banana Count   |  Update Cumulative Banana (This Block) |
|:---:|---|---|----|----|----|
| 0,0 | N/A | N/A | N/A  | 7   | 7|
| 1,0 | N/A | 7 | 7  | 6   | 7 + 6 = 13|
| 1,1 | 7 | 0 | 7  | 4   | 7 + 4 = 11|
| 2,0 | N/A | 13 | 13  | 3   | 13 + 2 = 15|
| 2,1 | 11 | 13 | 13  | 5   | 13 + 5 = 18|
| 2,2 | 11 | 0 | 11  | 10   | 11 + 10 = 21|
| 3,0 | N/A | 15 | 15  | 9   | 15 + 9 = 24|
| 3,1 | 15 | 18 | 18  | 8   | 18 + 8 = 26|
| 3,2 | 18 | 21 | 21  | 12   | 21 + 12 = 33|
| 3,3 | 21 | 0 | 21  | 2   | 21 + 2 = 23|
| 4,1 | 24 | 26 | 26  | 2   | 26 + 2 = 28|
| 4,2 | 26 | 33 | 33  | 12   | 33 + 12 = 45|
| 4,3 | 33 | 23 | 33  | 7   | 33 + 7 = 40|
| 5,2 | 28 | 45 | 45  | 8   | 45 + 8 = 53|
| 5,3 | 45 | 40 | 45  | 2   | 45 + 2 = 47|
| __6,3__ | 53 | 47 | 53  | 10   | 53 + 10 = __63__|

The matrix for cumulative sum looks like this:

| R/C  | 0 | 1 | 2  | 3  |
|---|---|---|----|----|
| __0__ | 7 |0|0 |0 |
| __1__ | 13 |11 |0 |0 |
| __2__ | 15 | 18 | 21 |0 |
| __3__ | 24 | 26 | 33 | 23  |
| __4__ |0| 28 | 45 | 40 |
| __5__ |0|0| 53  | 47  |
| __6__ |0|0|0 | __63__ |

As we can see, the __end block__ has the __answer__.

The above implementation is `accepted`.

__Caution__ : Remember to use fast I/O for your preferred language as per the suggestion from the problem statement and find out what may disrupt them, so we can avoid it.

__Notes__:
* You can take input in any _pattern_, a different _pattern_ will have different _indices_ to point out the _adjacent blocks_. Compare and update according to your implementation.
* You can use _linked list_/_vector_/_an implementation of similar data structure_, too. Just remember that the __read/write__ time should be _constant_.
* You can solve this problem by a _recursive_ implementation. Memory limit for this particular problem is __64 MB__, so stacks from _recursion states_ won't throw `Memory Limit Exceeded` exception.

## Solution in C++

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Enabling fast I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases, numberOfColumns;

    cin >> testCases;
    for (int i = 1; i <= testCases; i++)
    {
        cin >> numberOfColumns;
        int bananaMatrix[2 * numberOfColumns - 1][numberOfColumns]; //Input matrix
        int maxBanana[2 * numberOfColumns - 1][numberOfColumns];    //Memoized matrix

        memset(maxBanana, 0, sizeof(maxBanana));       //Setting 0 to all cell, will update for maximum
        memset(bananaMatrix, 0, sizeof(bananaMatrix)); //Setting 0 to all cell, will update for inputs

        //Input for upper triangle
        for (int row = 0; row < numberOfColumns; row++)
            for (int column = 0; column <= row; column++)
                cin >> bananaMatrix[row][column];

        //Input for lower triangle
        int shiftedPosition = 1;
        for (int row = numberOfColumns; row < (numberOfColumns * 2) - 1; row++)
        {
            for (int column = shiftedPosition; column < numberOfColumns; column++)
                cin >> bananaMatrix[row][column];
            shiftedPosition++;
        }

        /*
        Now we memoize the maxBanna array.
        We will start from the 2nd row (array[1][*]).
        We will check which ever 2 adjacent blocks from up can give more banana and update from the max.
        */

        //Memoizing the upper triangle to store max value
        maxBanana[0][0] = bananaMatrix[0][0];
        for (int row = 1; row < numberOfColumns; row++)
        {
            for (int column = 0; column <= row; column++)
                if (column == 0)//Caution for negative indexes.
                    maxBanana[row][column] = maxBanana[row - 1][column] + bananaMatrix[row][column];
                else
                    maxBanana[row][column] = max(maxBanana[row - 1][column], maxBanana[row - 1][column - 1]) + bananaMatrix[row][column];
        }

        //Memoizing the lower triangle to store the max value
        shiftedPosition = 1;
        for (int row = numberOfColumns; row < (numberOfColumns * 2) - 1; row++)
        {
            for (int column = shiftedPosition; column < numberOfColumns; column++)
                maxBanana[row][column] = max(maxBanana[row - 1][column], maxBanana[row - 1][column - 1]) + bananaMatrix[row][column];
            shiftedPosition++;
        }
        cout << "Case " << i << ": " << maxBanana[2 * numberOfColumns - 2][numberOfColumns - 1] << "\n";
    }

    return 0;
}
```
