# LightOJ 1138 - Trailing Zeroes (III)

### Short Description:
First line contains an integer **T**, which denotes the nubmer of test cases to follow. Each test cases contains an integer **Q**, for which we need to find the minimum natural number **N** such that, **N!** has exactly **Q** zeros on its trail (trailling zeros).

### Before we dive into the discussion:
**N!** or **N Factorial** = 1 x 2 x 3 x ... x N 
**5!** = 1 x 2 x 3 x 4 x 5 = **120** and **120** has **one** zero on its trail.

### Brute-force Approach:
Brute-force approach would be **loop**ing through all **natural numbers** & finding its **factorial** & then find the number of **trailling zeros** of this factorial value. If the number of **trailling zeros** is equal to **Q**, then we have our answer.
This solution won't work for the given input, as the factorial value of the possible answer could be too large & looping through all possible natural numbers in the valid answer range would be too slow.

### Better Approach:
We can break down the problem in finding two separate things:
1. Calculate the number trailling zeros in **N!**.
2. Find the **minimum** natural number with exactly **Q** trailling zeros.

**Follow these links**, if you want to learn how to find the number of trailling zeros in **N!**
1. [Number of Trailing Zeroes of Factorial - forthright48](https://forthright48.com/number-of-trailing-zeroes-of-factorial/)
2. [Number of Trailing Zeroes of Factorial - geeksforgeeks](https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/#:~:text=A%20simple%20method%20is%20to,till%20the%20remainder%20is%200)

Now, we know how to find the number of trailling zeros in **N!** but, how do we find the minimum natural number with the given number of trailling zeros?






