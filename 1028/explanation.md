# Problem Title : Trailing Zeroes (I)
## Problem link- https://lightoj.com/problem/trailing-zeroes-i


First of all, let us consider the fact: how we convert a 10 base number to a 2 base number. Simple it is. We have to divide the number with 2 until we get the quotient = 0. Now, we will try to convert the number 156 from base 10 to base 2.


![](https://imgur.com/WvioaJT.png)

                               
The binary representation of the number (156)<sub>10</sub> will be (10011100)<sub>2</sub>. The first remainder actually represents the last digit. We need to find the number of bases when converted from base 10, there will be at least one trailing zero. For the the last digit has to be zero. We don't need to see the rest. The last digit becomes 0 only if the number N is divided by the base.

In the image, we can see that we get 0 as remainder only when the number N is divided by the base. Only then we can get the first remainder as 0. So, we need to find out the number of divisors of N. N is always divided by 1. But we have to ignore it as the question demands us to find base from 2 to infinity. So, we have to reduce our answer by 1.

In order to solve the problem, we need to find the number of divisors and then reduce it by 1.

We know that if the prime factorization of a number N is p<sub>1</sub><sup>e1</sup>⋅p<sub>2</sub><sup>e2</sup>⋯p<sub>k</sub><sup>ek</sup>, where p<sub>i</sub> are distinct prime numbers, then the number of divisors is:
d(n)=(e1+1)*(e2+1)⋯(ek+1)

So, the answer will be d(n)-1.