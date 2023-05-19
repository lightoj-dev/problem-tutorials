# LOJ 1070 - Algebraic Problem

## Summary
Given three non-negative integers, a+b = **p**, ab = **q** and **n** we have to find the value of $a^n$ + $b^n$. a and b not necessarily have to be integers. There will be no such input so that we have to find the value of $0^0$

## Prerequisite
Matrix Exponentiation: https://www.youtube.com/watch?v=QcT5T-46iFA

**unsigned long long int** in C/C++: https://www.geeksforgeeks.org/maximum-value-of-unsigned-long-long-int-in-c/ (language specific). Implementations of **unsigned long long int** have a modulo behavior when performing arithmetic operations. Any arithmetic manipulation with unsigned long long int's will be taken modulo $2^{64}$ automatically.

## Solution
Let's define:

F(n) = $a^n$ + $b^n$

=> F(0) = $a^0$ + $b^0$ = 2

=> F(1) = a + b = **p**

$a^2$ +  $b^2$ = $(a+b)^2$ - 2ab

=> $a^2$ +  $b^2$ = (a + b) * (a + b) - ab * ( $a^0$ + $b^0$ )

=> F(2) = $a^2$ +  $b^2$ = **p** * (a + b) - **q** * ( $a^0$ + $b^0$ )

$a^3$ +  $b^3$ = (a + b) * ( $a^2$ +  $b^2$ ) - ab * (a + b)

=> F(3) = $a^3$ +  $b^3$ = **p** * ( $a^2$ +  $b^2$ ) - **q** * (a + b)

$a^4$ +  $b^4$ = (a + b) * ( $a^3$ +  $b^3$ ) - ab * ( $a^2$ +  $b^2$ )

=> F(4) = $a^4$ +  $b^4$ = **p** * ( $a^3$ +  $b^3$ ) - **q** * ( $a^2$ +  $b^2$ )

Observing the pattern we can conclude:

F(n) = **p** * F(n-1) - **q** * F(n-2) 

It's a linear recurrence that can be solved using matrix exponentiation technique.

$$
\begin{pmatrix}
p & -q \\
1 & 0
\end{pmatrix}
\begin{pmatrix}
F(1) \\
F(0)
\end{pmatrix} =
\begin{pmatrix}
F(2) \\
F(1)
\end{pmatrix}
$$

$$
\begin{pmatrix}
p & -q \\
1 & 0
\end{pmatrix} ^ {2}
\begin{pmatrix}
p \\
2
\end{pmatrix} =
\begin{pmatrix}
F(3) \\
F(2)
\end{pmatrix}
$$

$$
\begin{pmatrix}
p & -q \\
1 & 0
\end{pmatrix} ^ {n}
\begin{pmatrix}
p \\
2
\end{pmatrix} =
\begin{pmatrix}
F(n+1) \\
F(n)
\end{pmatrix}
$$

## Complexity
- Time Complexity: O(T * $k^3$ $log{_2}{n}$). Here, k = 2
- Memory Complexity: O( $k^2$ ).

## Code

### C++

```cpp
#include <bits/stdc++.h>
 
using namespace std;


typedef unsigned long long ull;

struct Matrix {
    vector <vector <ull>> mat;

    Matrix(int n) {
        mat.assign(n, vector <ull> (n, 0));
    }
};

Matrix mat_multiply(const Matrix& A, const Matrix& B) {
    int n = A.mat.size();
    Matrix res(n);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k) {
                res.mat[i][j] += A.mat[i][k] * B.mat[k][j];
            }
        }
    }
    
    return res;
}

Matrix binpow(Matrix &A, int power) {
    int n = A.mat.size();
    Matrix res(n);

    for(int i = 0; i < n ; ++i) {
        for(int j = 0; j < n; ++j) {
            res.mat[i][j] = (i == j? 1:0); // identity matrix
        }
    }

    while (power > 0) {
        if (power & 1) {
            res = mat_multiply(res, A);
        }
        power >>= 1;
        A = mat_multiply(A, A);
    }

    return res;
}

int main(int argc, const char *argv[]) {
     
    // for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int ts = 1; ts <= t; ++ts) {
        ull p, q, n;
        cin >> p >> q >> n;

        Matrix A(2);
        A.mat[0][0] = p;
        A.mat[0][1] = -q;
        A.mat[1][0] = 1;

        A = binpow(A, n);

        cout << "Case " << ts << ": " << A.mat[1][0]*p + (A.mat[1][1]<<1) << '\n';
    }

    return 0;
} 
```
