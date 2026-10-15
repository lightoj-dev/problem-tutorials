# Tutorial for 1244 - Tiles

## Problem Summary

We need to find the number of ways to completely cover a $2 \times N$ board using the given 6 shapes without any overlapping tiles or empty spaces. Since the answer can be very large, we must output it modulo $10007$.

## Finding the Recurrence Relation

Let $A_n$ be the number of ways to perfectly tile a $2 \times n$ board.

**Base Cases:**

- $A_0 = 1$
- $A_1 = 1$ (1 way to place a single vertical shape)
- $A_2 = 2$ (2 ways: 2 vertical shapes or 2 horizontal shapes)
- $A_3 = 5$ (5 ways: 3 vertical, 2 horizontal and 1 vertical, 1 vertical and 2 horizontal, 2 L shaped together that cover 2\*3, same 2 L shaped together that cover 2\*3)

So, when we mathematically compress this infinite chain of possibilities, we get a recurrence relation:

$$A_n = 2A_{n-1} + A_{n-3}$$

## Matrix Exponentiation

Since $N$ can be up to $10^9$, calculating the sequence step-by-step using a basic loop will cause a **Time Limit Exceeded (TLE)**. We need to optimize this to $O(\log N)$ time using **Matrix Exponentiation**.

We can represent our recurrence relation using a $3 \times 3$ transition matrix $T$:

$$\begin{pmatrix} A_n \\ A_{n-1} \\ A_{n-2} \end{pmatrix} = \begin{pmatrix} 2 & 0 & 1 \\ 1 & 0 & 0 \\ 0 & 1 & 0 \end{pmatrix} \begin{pmatrix} A_{n-1} \\ A_{n-2} \\ A_{n-3} \end{pmatrix}$$

Given the base cases $A_0 = 1$, $A_1 = 1$, and $A_2 = 2$, we can calculate $A_n$ by raising the transition matrix $T$ to the power of $n-2$ and multiplying it by the base-case vector:

$$\begin{pmatrix} A_n \\ A_{n-1} \\ A_{n-2} \end{pmatrix} = T^{n-2} \begin{pmatrix} A_2 \\ A_1 \\ A_0 \end{pmatrix} = T^{n-2} \begin{pmatrix} 2 \\ 1 \\ 1 \end{pmatrix}$$

## Code Explanation

- **`multiply(A, B, mod)`**: This function takes two $3 \times 3$ matrices and multiplies them row-by-column. It applies the modulo arithmetic at every addition to prevent integer overflow.
- **`power(A, n, mod)`**: This function uses Binary Exponentiation. Instead of multiplying the matrix $n$ times, it repeatedly squares the matrix and halves the exponent. This is what brings the time complexity down from $O(N)$ to $O(\log N)$.
- **`tiles(n)`**: This handles the base cases directly. For larger $N$, it builds the transition matrix $T$, calls the `power` function to calculate $T^{n-2}$, and then extracts the final answer by multiplying the top row of the resulting matrix by our base cases ($A_2, A_1, A_0$).

## Complexity

- **Time Complexity:** $O(\log N)$ per test case. Matrix multiplication takes a constant $3^3$ operations, and we do this $\log_2(N)$ times.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B, ll mod)
{
    vector<vector<ll>> C(3, vector<ll>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

// Iterative matrix exponentiation (binary exponentiation)
vector<vector<ll>> power(vector<vector<ll>> A, ll n, ll mod)
{
    vector<vector<ll>> result = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}; // identity matrix
    while (n > 0)
    {
        if (n & 1)
            result = multiply(result, A, mod);
        A = multiply(A, A, mod);
        n >>= 1;
    }
    return result;
}

ll tiles(ll n, ll mod = 1e4 + 7)
{
    // Base cases
    if (n == 0) return 1;
    else if (n == 1) return 1;
    else if (n == 2) return 2;

    // Transition matrix
    vector<vector<ll>> T = {{2, 0, 1}, {1, 0, 0}, {0, 1, 0}};

    // Fast-forward matrix to N-2 steps
    vector<vector<ll>> Tn = power(T, n - 2, mod);

    // Calculate final answer using top row and base cases: (Tn[0][0]*A_2 + Tn[0][1]*A_1 + Tn[0][2]*A_0)
    ll ans = (2 * Tn[0][0] + 1 * Tn[0][1] + 1 * Tn[0][2]) % mod;
    return ans;
}

void Rupalisaurus()
{
    ll n;
    cin >> n;
    cout << tiles(n) << "\n";
}

int32_t main()
{
    fast_io;

    ll t, tc = 0;
    if (cin >> t) {
        while (t--)
        {
            cout << "Case " << ++tc << ": ";
            Rupalisaurus();
        }
    }
    return 0;
}
```
