# 1142 - Summing Up Powers (II)

## Problem Specification

The problems asks you to find ![equation](https://latex.codecogs.com/svg.latex?A&plus;A%5E2&plus;A%5E3&plus;...&plus;A%5Ek) for a given ![equation](https://latex.codecogs.com/svg.latex?A) and ![equation](https://latex.codecogs.com/svg.latex?k), where ![equation](https://latex.codecogs.com/svg.latex?A) is an ![equation](https://latex.codecogs.com/svg.latex?n%20%5Ctimes%20n) matrix and ![equation](https://latex.codecogs.com/svg.latex?k) is an integer (![equation](https://latex.codecogs.com/svg.latex?1%20%5Cleq%20n%20%5Cleq%2030%2C%201%20%5Cleq%20k%20%5Cleq%2010%5E9%2C%20%5Cleq%2020) test cases). You have to print **only the last digit** for every cell of the matrix.

## Some discussions and insights

Without any time limit, the problem looks very simple. Starting with ![equation](https://latex.codecogs.com/svg.latex?A), you keep adding it to the result and keep multiplying it with ![equation](https://latex.codecogs.com/svg.latex?A). But it obviously fails because the time complexity becomes ![equation](https://latex.codecogs.com/svg.latex?O%28k%20%5Ccdot%20n%5E3%29). Hmm. That's a problem. Let's try to solve some different problems related to this.

## Hint 1

Can you find ![equation](https://latex.codecogs.com/svg.latex?A%5Ek) only, for the same constraints, in ![equation](https://latex.codecogs.com/svg.latex?O%28%5Clog%20k%20%5Ccdot%20n%5E3%29) time? If you can't, you might want to learn about it from this [link](https://en.wikipedia.org/wiki/Modular_exponentiation). Our problem directly needs this knowledge.

## Hint 2

Let's assume you can find ![equation](https://latex.codecogs.com/svg.latex?A%5Ek) using modular exponentiation (commonly known as _bigmod_). Have you noticed how _exactly_ bigmod works, or how it does what it does? Can we do something similar here?

## Solution

Let, ![equation](https://latex.codecogs.com/svg.latex?S%28k%29%20%3D%20A&plus;A%5E2&plus;A%5E3&plus;...&plus;A%5Ek).

### Case 1: k is even

![equation](https://latex.codecogs.com/svg.latex?S%28k%29%20%5C%5C%20%3D%20A%20&plus;%20A%5E2%20&plus;%20A%5E3%20&plus;%20...%20&plus;A%5Ek%20%5C%5C%20%3D%20A%20&plus;%20A%5E2%20&plus;%20...%20&plus;%20A%5E%7B%5Cfrac%7Bk%7D%7B2%7D%7D%20&plus;%20A%5E%7B%5Cfrac%7Bk%7D%7B2%7D&plus;1%7D%20&plus;%20...%20&plus;%20A%5Ek%20%5C%5C%20%3D%20%28A%20&plus;%20A%5E2%20&plus;%20...%20&plus;%20A%5E%7B%5Cfrac%7Bk%7D%7B2%7D%7D%29%20&plus;%20A%5E%7B%5Cfrac%7Bk%7D%7B2%7D%7D%20%5Ccdot%20%28A%20&plus;%20A%5E2%20&plus;%20...%20&plus;%20A%5E%7B%5Cfrac%7Bk%7D%7B2%7D%7D%29%20%5C%5C%20%3D%20S%28%5Cfrac%7Bk%7D%7B2%7D%29%20&plus;%20A%5E%7B%5Cfrac%7Bk%7D%7B2%7D%7D%20%5Ccdot%20S%28%5Cfrac%7Bk%7D%7B2%7D%29)
Isn't this recurrence beautiful? :tada: To find ![equation](https://latex.codecogs.com/svg.latex?S%28k%29), you can solve for ![equation](https://latex.codecogs.com/svg.latex?S%28%5Cfrac%7Bk%7D%7B2%7D%29), find ![equation](https://latex.codecogs.com/svg.latex?A%5E%7B%5Cfrac%7Bk%7D%7B2%7D%7D) in ![equation](https://latex.codecogs.com/svg.latex?O%28%5Clog%20k%20%5Ccdot%20n%5E3%29) time using modular exponentiation, do necessary calculation and produce the result. but what about when ![equation](https://latex.codecogs.com/svg.latex?k) is odd? Can you find it similarly?

### Case 2: k is odd

![equation](https://latex.codecogs.com/svg.latex?S%28k%29%20%5C%5C%20%3D%20A%20&plus;%20A%5E2%20&plus;%20A%5E3%20&plus;%20...%20&plus;A%5Ek%20%5C%5C%20%3D%20A%20&plus;%20A%5E2%20&plus;%20...%20&plus;%20A%5E%7B%5Clfloor%7B%5Cfrac%7Bk%7D%7B2%7D%7D%5Crfloor%7D%20&plus;%20A%5E%7B%5Clfloor%7B%5Cfrac%7Bk%7D%7B2%7D%7D%5Crfloor&plus;1%7D%20&plus;%20...%20&plus;%20A%5E%7B%5Clfloor%7B%5Cfrac%7Bk%7D%7B2%7D%7D%5Crfloor%5Ccdot%202%7D%20&plus;%20A%5Ek%20%5C%5C%20%3D%20%28A%20&plus;%20A%5E2%20&plus;%20...%20&plus;%20A%5E%7B%5Clfloor%7B%5Cfrac%7Bk%7D%7B2%7D%7D%5Crfloor%7D%29%20&plus;%20A%5E%7B%5Clfloor%7B%5Cfrac%7Bk%7D%7B2%7D%7D%5Crfloor%7D%20%5Ccdot%20%28A%20&plus;%20A%5E2%20&plus;%20...%20&plus;%20A%5E%7B%5Clfloor%7B%5Cfrac%7Bk%7D%7B2%7D%7D%5Crfloor%7D%29%20&plus;%20A%5Ek%20%5C%5C%20%3D%20S%28%5Clfloor%7B%5Cfrac%7Bk%7D%7B2%7D%7D%5Crfloor%29%20&plus;%20A%5E%7B%5Clfloor%7B%5Cfrac%7Bk%7D%7B2%7D%7D%5Crfloor%7D%20%5Ccdot%20S%28%5Clfloor%7B%5Cfrac%7Bk%7D%7B2%7D%7D%5Crfloor%29%20&plus;%20A%5Ek)

So, it looks like the case is very similar for both the cases. In short,
![equation](https://latex.codecogs.com/svg.latex?S%28k%29%20%3D%20S%28%5Clfloor%7B%5Cfrac%7Bk%7D%7B2%7D%7D%5Crfloor%29%20&plus;%20A%5E%7B%5Clfloor%7B%5Cfrac%7Bk%7D%7B2%7D%7D%5Crfloor%7D%20%5Ccdot%20S%28%5Clfloor%7B%5Cfrac%7Bk%7D%7B2%7D%7D%5Crfloor%29) ( add ![equation](https://latex.codecogs.com/svg.latex?A%5Ek) if ![equation](https://latex.codecogs.com/svg.latex?k) is odd). Don't forget to take `%10` properly. :metal:.

The overall time complexity becomes ![equation](https://latex.codecogs.com/svg.latex?O%28%28%5Clog%20k%29%5E2%20%5Ccdot%20n%5E3%29).
## Code in C++

```cpp
#include <bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair
using namespace std;

// necessary matrix class
class matrix
{
public:
    int r, c;
    int arr[52][52];
    matrix(){}
    matrix(int rr, int cc)
    {
        r=rr; c=cc;
        int i, j;
        ffr(i,0,r) ffr(j,0,c) arr[i][j]=0;
    }

    void print()
    {
        int i, j;
        ffr(i,0,r)
        {
            ffr(j,0,c)
            {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
    matrix operator + (const matrix &b) const
    {
        int i, j;
        matrix niu(r,c);
        ffr(i,0,r)
        {
            ffr(j,0,c)
            {
                int temp = arr[i][j]+b.arr[i][j];
                if(temp>=10) temp-=10;
                niu.arr[i][j] = temp;
            }
        }
        return niu;
    }
    matrix operator * (const matrix &b) const
    {
        int i, j, p;
        int sum;
        matrix niu(r, b.c);
        ffr(i,0,r)
        {
            ffr(j,0,b.c)
            {
                sum=0;
                ffr(p,0,c)
                {
                    int temp = arr[i][p]*b.arr[p][j];
                    sum+=temp;
                }
                niu.arr[i][j]=sum%10;
            }
        }
        return niu;
    }
};

// modular exponentiation for matrix 

matrix bigMod(matrix x, int n)
{
    matrix res(x.r,x.c);
    bool unassigned=1;
    while (n>0)
    {
        if (n&1)
        {
            if(unassigned) res=x;
            else res = x*res ;
            unassigned=0;
        }
        x = x*x ;
        n >>= 1;
    }
    return res;
}

// Described S(k) function  in the recurrence
matrix func(matrix A, int k)
{
    if(k==0)
        return matrix(A.r,A.c);
    matrix ans(A.r,A.c), fn2 = func(A,k/2), ak2 = bigMod(A,k/2);
    if(k&1)
        ans=bigMod(A,k);
    return ans + fn2 + ak2*fn2;
}

/*

fk = a + a^2 + a^3 + ... a^k
   = f(k/2) + a^(k/2) . f(k/2) + (k is odd)? a^k:0

*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cc=1, tt; cin >> tt;
    while(tt--)
    {
        int k, N, i, j, x;
        cin >> N >> k;
        matrix A(N,N);
        ffr(i,0,N)
        {
            ffr(j,0,N)
            {
                cin >> x;
                if(x==10) x=0;
                A.arr[i][j]=x;
            }
        }
        matrix S = func(A,k);
        cout << "Case " << cc++ << ":\n";
        S.print();
    }
}
```
