# LightOj:1341-Aladdin and the Flying Carpet

----
**What the problem wants :** The problem gives you two numbers `a` and `b` for each test case, where `a` is the area of carpet and `b` the minimum length of a side, also the carpet can't be square and must be rectangular. So, for each test case you have to find out the number of pairs (x,y) such that x*y = a and x>=b , y>=b and x doesn't equal to y.

**General approach to the solution :** We can see that if `x*y = a` then x and y are both divisors of `a`. So our answer will be half the number of divisors of `a` minus divisors who are less than `b`. We will half the number of divisors because each pair will require two unique divisors. Both divisors can't be same because the carpet can't be square.  

`answer = {(number of divisors of 'a')/2} - (number of divisors less than 'b')`

**Example :** Lets look at an example. Lets say the input `a = 100` and `b = 3`.

```
    100 = 1 X 100
        = 2 X 50
        = 4 X 25
        = 5 X 20
        = 10 X 10
```

As we can see we can create 5 pairs { (1,100) , (2,50) , (4,25) , (5,20) , (10,10) } where for each pair (x,y) ; `x*y = a`. Now, by removing pairs where x or y is less than `b` we get the pairs { (4,25) , (5,20) , (10,10) }. Hence the answer is 3.

The main challenge however is counting the number of divisors within the given constraints. Since `a` and `b` can be positive number up to 10<sup>12</sup> . Brute forcing to find divisors will result in TLE (Time Limit Exceeded).

**Finding the number of total divisors:** In order to solve the problem within time limit, we have to use _prime factorization_ for finding number of divisors. Prime factorization is the process of breaking down a problem into all of its [prime factors](https://www.geeksforgeeks.org/prime-factor/).

Let `x` be an integer, `D` its number of divisors.

If, _x = p<sub>1</sub><sup>n<sub>1</sub></sup> * p<sub>2</sub><sup>n<sub>2</sub></sup> * ..... * p<sub>i</sub><sup>n<sub>i</sub></sup>_ . where, p<sub>i</sub> = i'th prime factors of x and n<sub>i</sub> is the power of i'th prime factor.

Then, _D = (n<sub>1</sub>+1)(n<sub>2</sub>+1)(n<sub>3</sub>+1) . . . . . (n<sub>4</sub>+1)_

For example for our earlier example for `a = 100`:

100 = 2<sup>2</sup> X 5<sup>2</sup>

Hence, D = (2+1)(2+1) = 9 . Which is correct. Since , divisors of 100 are { 1, 2, 4, 5, 10, 20, 25, 50, 100 }.

**Finding the prime factor and their powers :** In order to find the prime factors of a number, we will first pick the smallest prime (which is two). As long as the number is divisible by that prime number we will divide the number and update the number by the result. If it's no longer divisible we will try the same problem with the next smallest prime. We will continue doing so till we have looked through all possible primes for that number.

One thing to note that for this process we will need a list of all prime numbers less than 10^6. We used a special algorithm called [sieve of eratosthenes](https://www.geeksforgeeks.org/sieve-of-eratosthenes/) for that purpose as brute force approach is too slow for such large range.

Resources:

- [Wiki How's explanation of finding total number of divisors](https://www.wikihow.com/Determine-the-Number-of-Divisors-of-an-Integer) 
- [Total number of divisors of a number by geekforgeeks](https://www.geeksforgeeks.org/total-number-divisors-given-number/)
- [Sieve of eratosthenes](https://www.geeksforgeeks.org/sieve-of-eratosthenes/)
- [Prime Factor by geekforgeek](https://www.geeksforgeeks.org/prime-factor/)

----

## C++ code for solution

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<long long int> prime;    //List of primes
const int nx = 1e6 + 10;        // range of prime numbers

void generate_prime()           //For generating all primes within 10^6 using sieve of eratosthenes
{

    bool flag[nx]={};

    int rt = 1e3;               // because root of 10^6 is 10^3

    for(int i=3; i<rt; i+=2)
    {
        if(!flag[i])
        {
            for(int j=i*i; j<nx; j+=(i<<1))
            {
                flag[j] = true;
            }
        }
    }

    prime.push_back(2);
    for(int i=3; i<nx; i+=2)
    {
        if(!flag[i]) prime.push_back(i);
    }
}

long long int divisors(long long int n) //for counting total number of divisors of "n"
{
    long long int ans=1,siz;
    siz = prime.size();

    for(long long int i=0;i<siz && (prime[i]*prime[i])<=n ;i++) 
    {   
        
        long long int power = 0; 
        if(n%prime[i]==0)
        {   
            // for counting the power of each prime factor.
            while(n%prime[i]==0)
            {
                ++power;
                n/=prime[i];
            }
        }
        ans *=(power+1);
    }
    if(n!=1) ans<<=1;
    return ans;
}

int main()
{
    int t,cas=0;
    cin>>t;

    generate_prime();

    long long int siz = prime.size();

    while(t--)
    {
        long long int n,a,b,ans,rt;
        cin>>a>>b;

        rt = sqrt(a);

        if((b*b==a)||rt<b)      //to see if b is too large
        {
            cout<<"Case "<<++cas<<": "<<0<<'\n';
            continue;
        }

        ans = divisors(a);

        ans = ans/2;            // because number of pairs is 1/2 of number of divisors

        for(long long int i=1;i<b;i++)
        {
            if(a%i==0) --ans;   //For removing divisors less than "b"
        }

        cout<<"Case "<<++cas<<": "<<ans<<'\n';
    }

    return 0;
}

```
