# LOJ 1202 - Bishops #
---
<img src = "1203pr.gif" width="200"></img>

There is an infinite chessboard. Two bishops are there. (Bishop means the chess piece that moves diagonally).

Now you are given the position of the two bishops. You have to find the minimum chess moves to take one to another. With a chess move, a bishop can be moved to a long distance (along the diagonal lines) with just one move.

### Input ###

Input starts with an integer _T (≤ 10000)_, denoting the number of test cases.
Each case contains four integers _r1 c1 r2 c2_ denoting the positions of the bishops. Each of the integers will be positive and not greater than 10<sup>9</sup>. You can also assume that the positions will be distinct.

### Output ###

For each case, print the case number and the minimum moves required to take one bishop to the other. Print `impossible` if it's not possible.

## Solution ##

If a __Bishop__ makes a move from its __initial block__ to any __diagonal__ direction, the difference of new _x-coordinate_ and _y-coordinate_ from their __initial block__ is equal, `|c1-c2| = |r1-r2|`. This is how we know that the __destination block__ can be reached __diagonally__ directly in _1 move_. For example : from `(1,1)` to `(10,10)`, here `|1-10| = 9 = |1-10|`. If the condition is not met, either the position can not be taken in _1 move_ or it is `impossible`.

Now to determine whether it can be reached at all or `impossible`, we need to know if the block we are trying reach is of the __same color__ of the __Bishop's initial block__ or not. We already know diagonal blocks can be reached in 1 move. But in case of switching to a block of the __same color__ of its current position that is not __directly diagonally connected__, observing the chessboard we can see that we need to move to another block that is already __diagonally__ connected to the __destination block__ we want. In other words, there is always at least __1 block__ and at best __2 blocks__ in common between the __destination block__  and __initial block__. For example: `(1,1)` and `(5,3)` have only `(4,4)` in common where as `(2,5)` and `(5,4)` have `{(4,3),(3,6)}`. So, in any case, a block of the __same color__ that needs to be reached via a __common block__ will require only _2 moves_. To check whether color of the __initial block__ and __destination block__ are same or not, we can check whether `|c1-c2| % 2 = |r1-r2| % 2` or not. For example : from `(1,1)` to `(5,3)`, here `|1-5| % 2 = 0 = |1-3| % 2`. Point to be noted, `|1-5| = 4` and `|5-3| = 2` are both __even__. In another example, `(4,5)` to `(3,2)` is reachable by `(4,5) -> (2,3) -> (3,2)`. But in this case, `|4-3| = 1` and `|5-2| = 3` are both __odd__ . But in case of from `(4,5)` to `(3,3)` is not possible because they have no __common diagonal block__ and also `|4-3| = 1` which is __odd__ and `|5-3| = 2` which is __even__. Thus if `|c1-c2| % 2 = |r1-r2| % 2` is `true` we now know that travelling is possible in _2 moves_. Else, the __destination block__ is not of the __same color__ as its __initial block__ and thus it is `impossible` to reach because there is not a single set of _(Black,White)_ or vice versa that is diagonally connected resulting in a __Bishop__ not able to switch to a block of __different color__.
 
The above implementation is `accepted`.

## Solution in C ##
```c
#include <stdio.h>
#include <math.h>
int main()
{
    int cases, c1, r1, c2, r2, c, r;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++)
    {
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        c = abs(c1 - c2);
        r = abs(r1 - r2);
        if (c == r)
            printf("Case %d: 1\n", i);
        else
        {
            if (c % 2 == r % 2)
                printf("Case %d: 2\n", i);
            else
                printf("Case %d: impossible\n", i);
        }
    }
    return 0;
}
```