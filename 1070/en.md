# LOJ 1070 - Alebraic Problem

## Summary
Given three non-negative integers, a+b = **p**, ab = **q** and **n** we have to find the value of $a^n$+$b^n$. a and b not necessarily have to be integers.

## Prerequisite
Binary Exponentiation: https://cp-algorithms.com/algebra/binary-exp.html

Matrix Exponentiation: https://www.youtube.com/watch?v=QcT5T-46iFA

## Solution


## Complexity
- Time Complexity: O(T * $k^3$ log(n)). Here, k = 2
- Memory Complexity: O(1).

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