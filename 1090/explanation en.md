# Light OJ 1090 - Trailing Zeroes (II)
## Problem Link: https://lightoj.com/problem/trailing-zeroes-ii


We need to find the number of trailing zeros from the given function.

![](https://imgur.com/oweCsn0.png)

What is the meaning of trailing zero? It means a number has zero/zeros at the end. We can also say that the last digits (probably a single digit) are/is zero of a particular number. From which we can come to this conclusion that the number is divisible by 10.

**For example:**<br>
100 = 10 X 10 (as there are two trailing zeros, there are two 10)

9000 =9 X 10 X 10 X 10 (as there are three trailing zeros, there are three 10)

Let’s say we want to write the number 10 as product of two numbers. We can write 10 as (2 X 5). That means if the number has five number of 10, then there will be such five numbers of (2 X 5).

100 = 10 X 10 = (2 X 5) X (2 X 5) [two (2 X 5)]

**So, we can say that we will get (2 X 5) as many as the number of trailing zeros.**

If a number can be expressed as the product of x number of 2 and y number of 5 (other multiples may present), then there will be min(x, y) numbers of (2 X 5) unique pairs. This will be the number of trailing zeros in the number n.

**For example:** n=20 = 2 X 2 X 5

Here x=2, y=1. The number of unique (2 X 5) is min(x, y) = min( 2, 1) =1. So, the number of trailing zero is 1.
n=50 = 2 X 5 X 5

Here x=1, y=2. The number of unique (2 X 5) is min(x, y) = min(1, 2) =1. So, the number of trailing zero is 1.

Now we are going to solve the problem dividing it into 3 parts.

**1st part: Calculation of number of 2 and 5 from nCr**<br>
**2nd part: Calculation of number of 2 and 5 from n^p**<br>
**3rd part: Combining 1st part and 2nd part to determine the final output**


## **1st Part — Calculation of nCr**

![](https://i.imgur.com/6iXfN6n.png)

We will now only focus on number of 2 s and 5 s in this formula ignoring other multiples.

![](https://i.imgur.com/qZnHk1Z.png)

In this way , we are going to find the number of 2s and 5s from nCr.

## **2nd Part — Calculation of n^p**
First of all, we are going to find the number of (2 X 5) in the number n. Let the number of 2 be x and the number of 5 be y. For the power, we will get px number of 2s and py number of 5s.

![](https://i.imgur.com/4UMhhdS.png)

Let n = 140³. Then:
n= 140³ = (2² X 5¹X 7¹)³ = 2⁶ X 5³ X 7³
Hence the number of 2 will be = px = 3 X 2 = 6 and the number of 5 will be = py = 3 X 1= 3

## **3rd Part — Final calculation**
Taking the number of 2 and 5 from the first part and second part, we will count the total number.

![](https://i.imgur.com/DJMEvCj.png)

**So, the number of trailing zeros will be = min(i-k-m+px , j-l-n+py).**


**NB:**
The finding process of number of 2 and 5 of 1st part and 2nd part is different. On first part we have found out the number of 2 and 5 of N!. That means 1X2X3X....N. But on second part we have actually prime factorized the number N in order to calculate the count of power of 2 and 5. Prime factorization of a number means to represent the number by prime numbers.

