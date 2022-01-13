# LOJ-1158: Anagram Division
---
### Abridge
Given a string **s** and a positive integer **d**, you have to determine how many permutations of **s** are divisible by **d**.
Notice the constrains: $1<=|s|<=10$, $1<=d<=1001$.

### Approach
This problem can be solved by using a classic DP method and to achieve the final result, we do an extra filter.
Let `dp[mask][remainer]` be the number of permutaions of numbers which are indexed identically to index of on bit (bit 1) in mask and having remainder equal to `remainder` divided by d.


### Code



