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

## Understanding 1
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

We can clearly see a repeatitive pattern. Here {1, 4, 7, 10...} positions are not divisible by 3 and rests are. 

Curious minds will want to know "why?". Simple! 
First, you may know that calcuting if a number is divisible by 3 is super easy. You just add all digits and see if the sum is divisible by 3 or not. So finding out if 123456 is divisible by 3 is equal to finding out if (1 + 2 + 3 + 4 + 5 + 6) = 21 is divisible by 3 or not. 
Now focus on the table. Each time we construct new position we just add the position-number to the previous value of the sequence, right? Let's follow an example. We have found out the 5th position in this sequence is 12345 which is divisible by 3 (12345 % 3 = 0; 12345 modulo 3 is zero. Also in other words (1 + 2 + 3 + 4 + 5) % 3 = 0). Now we construct 6th position in the sequence by just appending 6 to the last of the 5th number (123456). To calcuate if new number is divisible by 3 we can check that (1 + 2 + 3 + 4 + 5 + 6) % 3 is equal to 0 or not. Now after messing with paranthesis, you can see that (1 + 2 + 3 + 4 + 5 + 6) % 3  = ( (1 + 2 + 3 + 4 + 5) + 6) % 3. In other words for every **n***, *seq[n]** % 3 = (**seq[n - 1]** + n) % 3 = (**seq[n - 1]** % 3 + n % 3) % 3 (From modular arithmatic).

Now look at this table:
| Position at the sequence | Number      | Number % 3 | Previous_number % 3 | Position % 3 | (Previous_number % 3 + Position % 3) % 3 |
|--------------------------|-------------|------------|---------------------|--------------|------------------------------------------|
| 1                        | 1           | 1          | -                   | 1            | Default value to 1                       |
| 2                        | 12          | 0          | 1                   | 2            | ( 1 % 3 + 2 % 3) % 3 = 0                 |
| 3                        | 123         | 0          | 0                   | 0            | ( 0 % 3 + 0 % 3) % 3 = 0                 |
| 4                        | 1234        | 1          | 0                   | 1            | ( 0 % 3 + 1 % 3) % 3 = 1                 |
| 5                        | 12345       | 0          | 1                   | 2            | ( 1 % 3 + 2 % 3) % 3 = 0                 |
| 6                        | 123456      | 0          | 0                   | 0            | ( 0 % 3 + 0 % 3) % 3 = 0                 |
| 7                        | 1234567     | 1          | 0                   | 1            | ( 0 % 3 + 1 % 3) % 3 = 1                 |
| 8                        | 12345678    | 0          | 1                   | 2            | ( 1 % 3 + 2 % 3) % 3 = 0                 |
| 9                        | 123456789   | 0          | 0                   | 0            | ( 0 % 3 + 0 % 3) % 3 = 0                 |
| 10                       | 12345678910 | 1          | 0                   | 1            | ( 0 % 3 + 1 % 3) % 3 = 1                 |

Does the pattern make sense now? 

## Understanding 2
Previous undestanding is not enough to give you an AC, right. Now Lets look at the table a bit differently. Now we will add cumulative sum too and replace true/false with zero/one.

| Position at the sequence | Number      | Is divisible by 3 | Cumulative sum over divisibility |
|--------------------------|-------------|-------------------|----------------------------------|
| 1                        | 1           | 0                 | 0                                |
| 2                        | 12          | 1                 | 1                                |
| 3                        | 123         | 1                 | 2                                |
| 4                        | 1234        | 0                 | 2                                |
| 5                        | 12345       | 1                 | 3                                |
| 6                        | 123456      | 1                 | 4                                |
| 7                        | 1234567     | 0                 | 4                                |
| 8                        | 12345678    | 1                 | 5                                |
| 9                        | 123456789   | 1                 | 6                                |
| 10                       | 12345678910 | 0                 | 6                                |

Here cumulative sum for position **n** simply says "Between position 1 to **n** how many numbers are divisible by 3". Now can you tell how many numbers are divisible by 3 from position 4 to 7? We simply take the cumulative sum of position 7 and substract cumilative sum of position 3 (Because cumulative sum for position 7 says how many number are divisible by 3 from position 1 to 7, and we just substract how many numbers where divisible by 3 before the 4rth position).

## Understanding 3
Now we know that cumulative sum can be the key to success. We just have to find it smartly. By looking at the last table we can get that {1, 4, 7, 10, ...} are not divisible by 3. And all this positions are also 1 modulo 3 (position % 3 = 1). So if we get a position which is 1 modulo 3 it will not be divisible, right? (If position % 3 = 1 then not divisible by 3.)
Now, finding out how many numbers are divisible by 3 from 1 to **n** is quite equal to finding how many numbers are not divisible by 3 and substract the answer from **n**. (numbers_divisible_by_3_from_1_to_n = n - numbers_not_divisible_by_3)
