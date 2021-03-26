#LOJ-1005 Rooks
---
TAGS: Combinatorics, combination and permutation
We are given a 2D square array of size `n` and given `k` rooks. We have to find out how many way we can place all these rooks in the `n*n` chess board. There is only one rule: `No two rooks can be at attacking position.`

### Prerequisites to understand the problem completely
1) [How rook works](https://en.wikipedia.org/wiki/Rook_(chess)#:~:text=The%20rook%20moves%20horizontally%20or,a%20special%20move%20called%20castling.)
2) [How permutations and combinations works](https://www.mathsisfun.com/combinatorics/combinations-permutations.html)

## Solution 1
Let's clear our understanding about the problem
1) If we place a rook at (i,j) position it will cover i'th row and and j'th column as rooks can go any vertical or horizontal postition accessible from it's current position.
2) As rook cannot be an attacking position every placement of a new rook will hold a new row and a new column as well.
  a) so if there is more rook than the square length then there is `zero` way to place all the rooks.

Now, when `n>=k` at first we can choose any cell from the board so for the first rook we have n * n options to choose a place. After we place the first rook it occupies exactly one cell from each column and row( see below table).


| |✔ | |✔| |
|--- | ---| ---|--- |--- |
| |✔| |✔| |
|✔|rook |✔|✔|✔|
| |✔| |✔| |
|✔|✔|✔|rook |✔|
