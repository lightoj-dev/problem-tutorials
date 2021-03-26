#LOJ-1005 Rooks
---
TAGS: Combinatorics, combination and permutation
We are given a 2D square array of size `n` and given `k` rooks. We have to find out how many way we can place all these rooks in the `n*n` chess board. There is only one rule: `No two rooks can be at attacking position.`

### Prerequisites to understand the problem completely
1) [How rook works](https://en.wikipedia.org/wiki/Rook_(chess)#:~:text=The%20rook%20moves%20horizontally%20or,a%20special%20move%20called%20castling.)
2) [How permutations and combinations works](https://www.mathsisfun.com/combinatorics/combinations-permutations.html)

## Editorial 1
Let's clear our understanding about the problem
1) If we place a rook at (i,j) position it will cover i'th row and and j'th column as rooks can go any vertical or horizontal postition accessible from it's current position.
2) As rook cannot be an attacking position every placement of a new rook will hold a new row and a new column as well.
  a) so if there is more rook than the square length then there is `zero` way to place all the rooks.

Now, when `n>=k` at first we can choose any cell from the board so for the first rook we have n * n options to choose a place. After we place the first rook it occupies exactly one cell from each column and row( see below table). So for the next rook we have a (n-1)* (n-1) square board free options to choose. And for the next one (n-2) * (n-2) square board free options to choose. And so on. 
For k rooks our number of choice is `n`<sup>`2`</sup>` * (n-1)`<sup>`2`</sup>` * (n-2)`<sup>`2`</sup>` * (n-3)`<sup>`2`</sup>`.....* (n-k+1)`<sup>`2`</sup>
But in real we know that there is some duplicate ways as all rooks are same. The rooks can make k! way of formation without changing there position so we take only one. So our number of distinct rooks palcing is:<br>
<strong>(n<sup>2</sup> * (n-1)<sup>2</sup> * (n-2)<sup>2</sup> * (n-3)<sup>2</sup>.....* (n-k+1)<sup>2</sup>)/(k!)<strong>


| |✔ | | |✔| |
|--- |---| ---| ---|--- |--- |
| |✔| | |✔| |
|✔|rook| ✔|✔|✔|✔|
| |✔| | |✔| |
| |✔| | |✔| |
|✔|✔| ✔| ✔|rook |✔|

** There has arised a strong problem (overflow) with the above solution:
If the problem was a modulo problem that would not be a problem. But it's a non-modulo problem where the problem setter gurrentees that our number of way will be not greater than 10<sup>14</sup>.
So what we will do is:
1) Find k! first (k! has to be less than 10<sup>14</sup> we will prove it later solution)
2) Then build (n<sup>2</sup> * (n-1)<sup>2</sup> * (n-2)<sup>2</sup> .....* (n-k+1)<sup>2</sup>) this one at a time using loops. And divide them (nominator and denominator) by their greatest common divisor (GCD) so there occurs no chance of being overflow.

## Solution(accepted) of Editorial 1 in c++
```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    long long test,n,m,t=0;
    cin>>test;
    while(test--){
        cin>>n>>m;
        printf("Case %lld: ",++t);
        if(m>n){
            cout<<0<<endl;
            continue;
        }
        long long ans=1,fact=1;
        ll k =m;
        while(k)fact*=k--;
        
        while(m){
            ll gcd = __gcd(n*n,fact);
            ll tem = (n*n)/gcd;
            
            fact/=gcd;
            ans=(ans*tem);
        	
            m--;
            n--;
           
        }
        //cout<<ans<<' '<<fact<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
```
