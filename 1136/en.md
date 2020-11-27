# 1136 - Division by 3

## Problem
Straight from the statement: "There is sequence 1, 12, 123, 1234, ..., 12345678910, ... . Now you are given two integers **A** and **B**, you have to find the number of integers from **A**th number to **B**th (inclusive) number, which are divisible by 3.

For example, let **A** = 3. **B** = 5. So, the numbers in the sequence are, 123, 1234, 12345. And 123, 12345 are divisible by 3. So, the result is 2."

Looking a bit into the sequence you will find out that for a certain position **A** the number can be found by simply appending all natural numbers from 1 upto **A** one after another. So if **A** = 5: sequence is 12345, if **A** = 12: sequence is 123456789101112.

Now you will be given two numbers **A** and **B**. You have to find out how many numbers are divisible by 3 on the position of **A**, **A+1**, ..., **B** (range is from **A** to **B**).

## Constrains: 
Test cases T (≤ 10000) and 1 ≤ A ≤ B < 2^31

## Observation
1. By looking at the constrains it is quite sure that bruteforce approach is going to gift us TLE. (If you calculate all the number from range **A** to **B** and try to find out who amoung them are divisible by 3 you will get time limit exceeded). So we need a very effecient approach. 
2. Numbers can be quite big. 

## Approach
Let get out hand dirty by finding out if numbers from the sequence are divisible by 3.

| Position at the sequence | Number      | Is divisible by 3 |
|--------------------------|-------------|-------------------|
| 1                        | 1           | false             |
| 2                        | 12          | true              |
| 3                        | 123         | true              |
| 4                        | 1234        | false             |
| 5                        | 12345       | true              |
| 6                        | 123456      | true              |
| 7                        | 1234567     | false             |
| 8                        | 12345678    | true              |
| 9                        | 123456789   | true              |
| 10                       | 12345678910 | false             |

We can clearly see a repeatitive pattern. Here {1, 4, 7, ...} positions are not divisible by 3 and rests are. 
