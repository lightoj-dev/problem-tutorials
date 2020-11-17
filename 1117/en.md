# 1117 - Helping Cicada

## This is a number theory problem and you have given `T` test cases and for each test cases you have `N`, a possible range, and `M` positive integer numbers, denoting the life cycles of the predators.

#### Summary

For the `T` group of input set, where each set consist of `N` and `M` numbers, you have to find how many of the numbers from `1 to N` can't be divided by any of given `M` numbers.

#### Solution

For any number `x`, `1 ~ n` it has `[n/x]` numbers of divisors, in a other word, there are `[n/x]` numbers that can be divisible by `x`, [a] means a is rounded down.

As now you have to deal with multiple divisors, from the (principle-of-inclusion-and-exclusion)[https://brilliant.org/wiki/principle-of-inclusion-and-exclusion-pie/] :
`AUBUC=A+B+C-A∩B-A∩C-B∩C+A∩B∩C`
If you summarize this, the pattern is you add the divisor counts of `N/LCM` of odd numbers and subtracts even.

As you have `M` divisors to deal with, if you check the binary of all the numbers from `1 ~ (2^M -1)`, you can see all possible combinations you need are presented there.

for example, let's consider sample test case 1:

```
N = 15
M = 3
{ 2,  3,  5 }
binary representation of 1 - (2^M - 1) or 7:

0001        // gets included
0010        // gets included
0011        // gets excluded
0100        // gets included
0101        // gets excluded
0110        // gets excluded
0111        // gets included
```

So the algorithm is:

- loop through all the numbers `1 ~ 1<<M`,
- check for the set bits, find their LCM and
- add to the count if the set bit count is negative, subtract otherwise.

#### Code
