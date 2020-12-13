# 1080 - Binary Simulation

_Given a binary number, we are about to do some operations on the number. Two types of operations can be here._

_`‘I i j‘` which means invert the bit from `i` to `j`_ (inclusive)

_`‘Q i‘` answer whether the ith bit is `0` or `1`_

_The MSB (most significant bit) is the first bit (i.e. i=1). The binary number can contain leading zeroes._

---

#### Summary

For the `T` group of input set, where each set consist of `S`, a binary bit pattern, and `Q`, number of queries, for each queries you have invert a range in the given bit pattern or answer if the asked bit is set/`1` or not/`0`.

#### Solution

For any number `x`, `1 ~ n` it has `[n/x]` numbers of divisors, in a other word, there are `[n/x]` numbers that can be divisible by `x`, [a] means a is rounded down.

As now you have to deal with multiple divisors, from the [principle-of-inclusion-and-exclusion](https://brilliant.org/wiki/principle-of-inclusion-and-exclusion-pie/) :

`AUBUC=A+B+C-A∩B-A∩C-B∩C+A∩B∩C`

If you summarize this, the pattern is you add the divisor counts of `N/LCM` of odd numbers and subtracts even.

As you have `M` divisors to deal with, if you check the binary of all the numbers from `1 ~ (2^M -1)`, you can see all possible combinations you need are presented there.

for example, let's consider sample test case 1:

```
N = 15
M = 3
{ 2,  3,  5 }
binary representation of 1 - (2^M - 1) or 7:

0001        // C     -> gets included
0010        // B     -> gets included
0011        // B∩C   -> gets excluded
0100        // A     -> gets included
0101        // A∩C   -> gets excluded
0110        // A∩B   -> gets excluded
0111        // A∩B∩C -> gets included
```

So the algorithm is:

- loop through all the numbers `1 ~ 1<<M`,
- check for the set bits, find their LCM and
- add `N/LCM` to the count if the set bit count is negative, subtract otherwise,
- print `N - count`, here `count` tracks all the number from `1-N` that can be divided at least one of the `M` numbers.

`Note: (1<<M) will works here as M is small`

#### Code

### C++

```cpp

```
