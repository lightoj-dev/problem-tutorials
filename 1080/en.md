# Loj 1080 - Binary Simulation

_Given a binary number, we are about to do some operations on the number. Two types of operations can be here._

_`‘I i j‘` which means invert the bit from `i` to `j`_ (inclusive)

_`‘Q i‘` answer whether the ith bit is `0` or `1`_

_The MSB (most significant bit) is the first bit (i.e. i=1). The binary number can contain leading zeroes._

---

#### Summary

For the `T` group of input set, where each set consist of `S`, a binary bit pattern, and `Q`, number of queries, for each queries you have invert a range in the given bit pattern or answer if the asked bit is set/`1` or not/`0`.

#### Solution

It's clear that a naive approach of `O(N)` complexity will give `TLE` in this input range. So you have to look for a faster way to make queries.

There are many Data structures, _segment tree_, _binary index tree_, for example, to handle this type of _range update and point query_ or _point update range query_ in a faster way.

In this tutorial you will go through segment tree with lazy propagation implementation version.

If you aren't already aware of Segment Tree and Lazy Propagation:

- [Hackerearth: Segment Tree and Lazy Propagation](https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/)
- [Cp-Algorithm: Segment Tree and it varieties](https://cp-algorithms.com/data_structures/segment_tree.html)

#### Code

### C++

```cpp

```
