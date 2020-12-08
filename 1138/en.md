# LightOJ 1138 - Trailing Zeroes (III)

### Short Description:
First line contains an integer **T**, which denotes the nubmer of test cases to follow. Each test cases contains an integer **Q**, for which we need to find the minimum natural number **N** such that, **N!** has exactly **Q** zeros on its trail (trailling zeros).

### Before we dive into the discussion:
**N!** or **N Factorial** = 1 x 2 x 3 x ... x N 
**5!** = 1 x 2 x 3 x 4 x 5 = **120** and **120** has **one** zero on its trail.

---
### Brute-force Approach:
Brute-force approach would be **loop**ing through all **natural numbers** & finding its **factorial** & then find the number of **trailling zeros** of this factorial value. If the number of **trailling zeros** is equal to **Q**, then we have our answer.
This solution won't work for the given input, as the factorial value of the possible answer could be too large & looping through all possible natural numbers in the valid answer range would be too slow.

--- 
### Better Approach:
We can break down the problem in finding two separate things:
1. Calculate the number trailling zeros in **N!**.
2. Find the **minimum** natural number with exactly **Q** trailling zeros.

**Follow these links**, if you want to learn how to find the number of trailling zeros in **N!**
1. [Number of Trailing Zeroes of Factorial - forthright48](https://forthright48.com/number-of-trailing-zeroes-of-factorial/)
2. [Number of Trailing Zeroes of Factorial - geeksforgeeks](https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/#:~:text=A%20simple%20method%20is%20to,till%20the%20remainder%20is%200)

Now, we know how to find the number of trailling zeros in **N!** but, how do we find the minimum natural number with the given number of trailling zeros?

**Trailling zeros of first 15 numbers [0 - 14]:** 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2 ..

If we see the sequence [here](https://oeis.org/A027868) carefully, it's very easy to realize that the number of trailling zeros forms a non-decreasing sequence. This should ring a bell, if you know a bit about **Binary Search**, see [this](https://www.youtube.com/watch?v=GU7DpgHINWQ&ab_channel=Errichto) video if you want to learn about it.

---
Now, with some knowledge of **Binary search**, we can finally solve this problem:
1. Set the values **[Low, High]** properly - our possible answer range.
2. Find the **Mid** value & calculate its number of trailling zeros.
3. Decide which **half** to search based on the number of trailling zeros of **Mid**.
4. Careful with possible integer **overflow**.
5. Careful with the **impossible** case, when there's no possible answer.
6. Format the output properly according to the output section.

---
See the code below if you still need some help with the implementation:

### C++
```
#include <bits/stdc++.h>

using namespace std;

const long long LIMIT = 1e18;

long long calculateTraillingZeros(long long number) {
    long long traillingZeros = 0;
    // finds the number of trailling zeros in number factorial
    for (long long i = 5; i <= number; i *= 5) {
        traillingZeros += (number / i);
    }
    return traillingZeros;
}

int main() {
    int testCase;
    scanf("%d", &testCase);
    for (int test = 1; test <= testCase; test++) {
        long long requiredTraillingZeros;
        scanf("%lld", &requiredTraillingZeros);
        // answer is set to a value -1, which can't be a valid answer
        long long low = 1, high = LIMIT, answer = -1;
        while (low <= high) {
            // select the mid, find its trailling zeros & decide what to do.
            long long mid = (low + high) / 2;
            long long traillingZeros = calculateTraillingZeros(mid);

            if (traillingZeros > requiredTraillingZeros) {
                // if traillingZeros is greater than requiredTraillingZeros, then we should try smaller values
                high = mid - 1;
            } else if (traillingZeros < requiredTraillingZeros) {
                // if traillingZeros is smaller than requiredTraillingZeros, then we should try bigger values
                low = mid + 1;
            } else {
                // if traillingZeros is equal to requiredTraillingZeros, it's a possible answer
                // so, we store it in answer & try the smaller values as we need to find the minimum possible value
                answer = mid;
                high = mid - 1;
            }
        }
        // if answer is still -1, then we haven't any possible answer
        if (answer == -1) printf("Case %d: impossible\n", test);
        else printf("Case %d: %lld\n", test, answer);
    }
    return 0;
}

```





