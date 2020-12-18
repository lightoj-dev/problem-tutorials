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

In this tutorial you will use the logic of the segment tree lazy propagation. If you aren't already aware of Segment Tree and Lazy Propagation, have a walk through these links:

- [Hackerearth: Segment Tree and Lazy Propagation](https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/)
- [Cp-Algorithm: Segment Tree and it varieties](https://cp-algorithms.com/data_structures/segment_tree.html)

Let's assume you got a proper knowledge on what is segment tree and how does lazy propagation works.

As there are two types of queries, _for update range query_, rather than updating the range, if you just _keep a track_ or _mark the node_, so that next time you go down to this node you will be aware of pending updates to make on it's predecessors, and for the for the second type of queries, while finding the desired node, make the pending updates.

#### Code

### C++

```cpp

```
