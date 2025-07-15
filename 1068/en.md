# LOJ-1068 – Investigation  
---  
**Tags:** `digit dp`, `dynamic programming`, `modulo math`

---

### Helpful Resources

- [Digit DP Tutorial – Codeforces Blog](https://codeforces.com/blog/entry/53960 "Digit DP – Codeforces")

---

## Problem Summary

You're given two integers `A` and `B`, and an integer `K`. Your task is to count how many numbers between `A` and `B` (inclusive) are divisible by `K` **and** whose sum of digits is also divisible by `K`.

This is a classic case for applying **Digit Dynamic Programming (Digit DP)**, since a brute-force approach will time out due to the constraint on the range (`A`, `B` ≤ `2^31`).

---

## Key Observations

1. We need to **track two properties** for a number:
   - Is the number divisible by `K`?
   - Is the **sum of its digits** divisible by `K`?

2. We can use **Digit DP** to solve this efficiently by building the number digit by digit, while tracking:
   - Current position in the digit array
   - Remainder of the number modulo `K`
   - Remainder of the digit sum modulo `K`
   - A `tight` flag to restrict digits to the current bound if we’re matching the prefix

3. We cannot take `K` directly in the state array due to memory limits.  
   However, we can observe that:
   - The maximum digit sum for any number ≤ `2^31` is `9 × 10 = 90`
   - So, if `K > 90`, **no valid number exists** in the range.

---

## Approach

- Extract digits of a number to process digit-by-digit with tight bound control
- Use memoization to cache overlapping subproblems (`pos`, `modNum`, `modSum`, `tight`)
- Count valid numbers between `1` to `B`, then subtract valid numbers between `1` to `A-1` to get the count in range `[A, B]`

---

## Time Complexity

- The number of states is bounded by: `pos (≤ 10) × modNum (≤ K) × modSum (≤ K) × tight (2)`
- Overall time complexity is **O(10 × K × K × 2)** = `O(K^2)` (acceptable since `K ≤ 90`)

---

## Solution (Java)

```java
import java.util.*;

public class Solution {
    static int[][][][] dp;
    static int[] digits;
    static int K;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int tc = 1; tc <= T; tc++) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            K = sc.nextInt();

            if (K > 90) {
                System.out.println("Case " + tc + ": 0"); 
                continue;
            }

            int res = countValid(B) - countValid(A - 1);
            System.out.println("Case " + tc + ": " + res);
        }
    }

    static int countValid(int x) {
        digits = extractDigits(x);
        int n = digits.length;
        dp = new int[n][K][K][2]; // pos, mod_num, mod_sum, tight
        for (int[][][] d1 : dp)
            for (int[][] d2 : d1)
                for (int[] d3 : d2)
                    Arrays.fill(d3, -1);

        return dfs(0, 0, 0, 1);
    }

    static int dfs(int pos, int modNum, int modSum, int tight) {
        if (pos == digits.length)
            return (modNum == 0 && modSum == 0) ? 1 : 0;

        if (dp[pos][modNum][modSum][tight] != -1)
            return dp[pos][modNum][modSum][tight];

        int limit = (tight == 1) ? digits[pos] : 9;
        int res = 0;

        for (int d = 0; d <= limit; d++) {
            int newTight = (tight == 1 && d == limit) ? 1 : 0;
            int newModNum = (modNum * 10 + d) % K;
            int newModSum = (modSum + d) % K;

            res += dfs(pos + 1, newModNum, newModSum, newTight);
        }

        return dp[pos][modNum][modSum][tight] = res;
    }

    static int[] extractDigits(int x) {
        List<Integer> list = new ArrayList<>();
        if (x == 0) 
            list.add(0); 
        while (x > 0) {
            list.add(x % 10);
            x /= 10;
        }
        Collections.reverse(list);
        return list.stream()
                    .mapToInt(i -> i)
                    .toArray();
    }
}
```
## Additional Notes

### Memory Limit Issues (MLE)

If you're facing **Memory Limit Exceeded (MLE)** on platforms like **LightOJ**, consider the following optimizations:

- **Use `Integer` instead of `int` in DP array** only if absolutely needed (not usually required here).
- Switch from a 4D array to a **HashMap with composite key encoding** like `pos * K * K * 2 + modNum * K * 2 + modSum * 2 + tight`. This reduces memory overhead at the cost of some performance.
- Use **`Integer[][][][]` DP** and `null` instead of `-1` if required to avoid initialization overhead.
- Avoid printing inside the DP recursion — this can blow up memory if prints are numerous.
- Avoid constructing large intermediate strings (like via `StringBuilder`) in recursive calls.

### Time Limit Exceeded (TLE)

If you’re running into **TLE**:

- Precompute and reuse DP table per test case wherever possible.
- Ensure `extractDigits()` and `countValid()` are efficient.
- Avoid unnecessary object creation inside recursive calls.
- Use `FastIO` for input/output on platforms with tight I/O constraints.

---

## Author

- Sandesh Atulya
- Find me at [LinkedIn](https://www.linkedin.com/in/sandesh-atulya/)