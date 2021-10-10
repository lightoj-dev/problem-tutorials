# LOJ 1024: Eid
### What the problem wants
We are given N numbers, we have to find out the Least Common Multiple (LCM) of them. All the numbers are between 0 and 10000 and N can be highest 1000.

### Observation
Elementary mathematics says that for two number a and b: a ✕ b = lcm(a, b) ✕ gcd(a, b)
Here lcm(a, b) is the least common multiple of a and b; gcd(a, b) is the greatest common divisor of a and b. Now gcd(a, b) is easy for us to calculate, Euclidean or Extended Euclidean GCD formula is effecient enough to calculate gcd of this range. So lcm(a, b) should also be easy to calculate, right? lcm(a, b) = (a ✕ b) / gcd(a, b)
Now we have solved things for 2 numbers. What about more? If we are given {3, 4, 6, 7, 19} as input can we find LCM of them? Yes. We can simply calculate lcm(3, 4) which gives 12; then calculate lcm(12, 6) which gives 12; then calculate lcm(12, 7) which gives 84; lastly calulcate lcm(84, 19) which gives 1596. Final lcm (1596) is the answer. We have calculated lcm of first two numbers and for rest of the numbers we have just calculated lcm of the previous answer and the current number. Easy, huh?
But there is a problem. As N can be highest 1000 and each number can get to 10000 result of the lcm calculation can get too long for computer data type (Unsigned long long in c++ can hold upto 2^64 but this time the lcm result gets even bigger than the range). So this approach fails.


We know that for two numbers A, B if they can be written in prime factorized format as
 
A = p1 <sup>a1</sup> * (p2 <sup>a2</sup> * p3 <sup>a3</sup> * ... ...* pk <sup>ak</sup> 

B = p1 <sup>b1</sup> * (p2 <sup>b2</sup> * p3 <sup>b3</sup> * ... ...* pk <sup>bk</sup>

Then lcm(A, B) = p1 <sup>max(a1, b1)</sup> * p2 <sup>max(a2, b2)</sup> * p3 <sup>max(a3, b3)</sup> * ... ...* pk <sup>max(ak, bk)</sup>

where p1, p2,...,pk are prime numbers; a1, a2, ..., ak, b1, b2, ..., bk are non-negative numbers and max(p, q) simply means highest number between p and q.
We can extend this idea for multple numbers as well.. for saveral numbers it would be.

lcm(A, B, C, ....) = p1 <sup>max(a1, b1, c1, ...)</sup> * p2 <sup>max(a2, b2, c2, ...)</sup> * p3 <sup>max(a3, b3, c3, ...)</sup> * ... ...* pk <sup>max(ak, bk, ck, ...)</sup>

So we can precalculate and store all the primes between 10000 and use them to factorize all the given numbers and find out the necessary numbers to calculate the lcm by the above equation.


Suppose, we are told to multiply "926" (in string format) and 13 (in integer format), Can we perform the task? Yes. We use elementary way to multiply. Lets iterate from right to left of the string that we are given. In each step we will hold the answer (ans = "") and a carry (carry = 0).
- First digit is 6 (from left). We multiply 6 with 13 which gives 78 (No need to add carry as carry is 0 in the beginning). We put the last digit (8) in the answer (ans = 8) and rest digits in carry (carry = 7).
- Second digit is 2. We multiply 2 and 13 which gives 26. As we had a carry (carry is not zero now) which gives us 26 + 7 (carry) = 33. We append last digit in the begininng of the ans (ans = 38) and assign rest digits in the carry (carry = 3).
- last digit is 9. We multiply 9, 13 and add carry with the answer. Which gives us 120. We append the last digit in the beginning of the answer (ans = 038) and carry = 12.
- As we still have some carry, we append the carry in the beginning of the answer. (ans = 12038). And the result is 12038.
Thus, by iterating we can multiply a string (integer) and a number in O(n) time.

### General approach
We can precalculate and store all the primes at first (By using Sieve of Eratosthenes). Then we can factorized all the numbers and calculate necessary numbers for generating lcm. As integer to integer multiplication cannot be done in this range (answer would be too big to be contained) we can make use of strings. As strings can have a big length we can simply multiply an integer and a string formated integer. This would make our process efficient enough to get an accepted verdict. 
Suppose we have come up with answer to be 2 <sup> 3 </sup> * 7 <sup> 2 </sup>. Then we can take "1" and multiply it with 2 for three times and 7 for two times to get the result. [Exponents cannot be to big so that we get Time Limit Exceeded, think about it]

Some programming language like python allows built in big integer fascilities which can be helpful (or even too slow to pass the judge). 

### Things to learn
Sieve of Eratosthenes, Number theory

### C++ implementation
```
#include "bits/stdc++.h"
using namespace std;

#define max(a, b) (a>b?a:b)

int p[1130], sz = 1;
bool siv[10000];
string ans = "Rahat Voch 8)";

string multyply(string a, int b){
  int carry = 0;
  ans = "";
  for(int i = 0; i < a.size(); i++){
    carry = ((a[i] - '0') * b + carry);
    ans += carry % 10 + '0';
    carry /= 10;
  }
  while(carry != 0){
    ans += carry % 10  + '0';
    carry /= 10;
  }
  return ans;
}

int n, a, num, t = 1, tc;

int main(){
  p[0] = 2;
  for(int i = 3; i * i <= 10000; i+=2){
    if(!siv[i]){
      for(int j = i*i; j <= 10000; j += i + i) siv[j] = 1;
    }
  }
  for(int i = 3; i <= 10000; i+=2) if(!siv[i])p[sz++] = i;
  for(scanf("%d", &tc); t <= tc; t++){
    scanf("%d", &n);
    map <int, int> pf;
    for(int i = 0; i < n; i++){
      scanf("%d", &a);
      for(int j = 0; j < sz && p[j]*p[j] <= a; j++){
        if(a % p[j] == 0){
          num = 1;
          while(a % p[j] == 0){
            num *= p[j];
            a /= p[j];
          }
          pf[p[j]] = max(pf[p[j]], num);
        }
      }
      if(a != 1) pf[a] = max(pf[a], a);
    }
    string ans = "1";
    for(map<int, int>:: iterator it = pf.begin(); it != pf.end(); it++){
      ans = multyply(ans, it->second);
    }
    reverse(ans.begin(), ans.end());
    printf("Case %d: %s\n", t, ans.c_str());
  }
  return 0;
}

```
