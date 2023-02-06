## Understanding The Problem Statement

First we identify what the problem wants, we have n coin denomination or values A<sub>i</sub> where for my approach we take i as 0<=i<=n 
and n has the constraint 1<=n<=50, and each of the coin with value A is given a count or the number of these coins we have, which is C<sub>i</sub>. We are also provided
K which is the value we wish to pay off using a valid coin combination.

The question simply asks us to find the number of ways by which we can pay off the required value using our available coins. 

## Prerequisites

- Basic Understanding of DP(Dynamic Programming) [DP-1 Jenny CS IT](https://youtu.be/lVR2u9lsxl8)
- Preliminary Idea of Coin Change Problem [DP#2 Jenny CS IT](https://youtu.be/L27_JpN6Z1Q)

## Solution Approach

This problem is essentially a variation of the classic dynamic programming problem, coin change. Here we first recognize that we need to store the values for the coin denominations
and the number of each of these coin types in two seperate arrays. Then we define the following formal definition of a recursive function:

coinchange(index,current_value): returns the number of ways by which we can pay off the target cost with the given coin denominations, and number of coins of each type

coinchange(index,current_value): {
                                      1 if current_value=0
                                      0 if i=n(since we are using 0-based indexing)
                                      coinchange<sub>ix</sub>(i+1,current_value-ix\*A<sub>i</sub>) if 0<=ix<=C[i] and 0<=i<n
                                  }
To explain this, we have two base cases if the current value becomes 0 then we return 1 as it represents 1 valid combination
and if the index approaches becomes n we return 0 as we went out of the bounds of the array we initialized or out of bounds of the n we were given but still could not
find a soltuion. The last statement involves a for loop from ix=0 upto ix<=C[i] being the number of coins of type A[i] we have and upon selecting each coin we make
a recursive call to the next coin. A sample recursion tree is given below
![RecursionTreeForMentionedImplementation](RecursionTree.jpg)
The test case for the given diagram is A={1,2,5} and C={3,2,2}.
In the tree above we can see upon each call the child branches or the recursive calls direct to all possible combinations, starting from one coin if ix=0 we don't select
that coin and move forward to the next coin, if ix=1 we select one of that specific coin and then move forward by substracting the total of the selected coins 
from the current value upon moving forward by making another recursive call. In this manner if ix=a we select a coins and then move to the next possible selection. In this
manner we can check all possible combinations. But it is not necessary to brute force through all possible combinations. We can eliminate some of the redundant or
repetitive calls by the use of [memoization](https://en.wikipedia.org/wiki/Memoization) which is essentially the process of storing computational results to prevent
recalculating them which might cause unnecessary reptitive computation as mentioned earlier. This can be done using a 2-state dp, the states tend to be reflected by
the number of arguments passed to the defined function which in this case is 2. So here we would take a 2D array with the size of rows as the maximum possible value for n +1 and
columns as the maximum possible value for K +1. In each computation, we store the value result in the dp array as per **dp\[index]\[current_value]**. In future computations,
if we find that the dp array contains our desired value we return it. Initially we set all the values to -1 in the dp array to easily identify if there is a result stored
for that specific combination of index and current_value. A sample implementation is given below:

## Solution
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 100000009
#define modulo 100000007
#define Max_n 55
#define Max_K 1005
#define Max_C 25
int n;
ll K;
vector<ll>A,C;

int dp[Max_n][Max_K];

ll coinchange(int i,int current_value){
  if(current_value==0){
    return 1;
  }
  if(i==n){
    return 0;
  }
  if(dp[i][current_value]!=-1){
    return dp[i][current_value];
  }
  dp[i][current_value]=0;
  for(int ix=0;ix<=C[i] && current_value-ix*A[i]>=0;ix++){
    dp[i][current_value]+=(coinchange(i+1,current_value-ix*A[i])%modulo);
  }
  return dp[i][current_value]%modulo;

}


void run_test_case(){
  memset(dp,-1,sizeof(dp));
  cin>>n>>K;
  A.resize(n);
  C.resize(n);
  for(ll &i:A){
    cin>>i;
  } 
  for(ll &i:C){
    cin>>i;
  }
  cout<<coinchange(0,K)<<endl;//we pass our desired value that being K to the function as the current_value, this value is changed in every recursive call
}

int main(void){
  int number_of_test_cases;
  cin>>number_of_test_cases;
  for(int current_case=1;current_case<=number_of_test_cases;current_case++){
    cout<<"Case "<<current_case<<": ";
    run_test_case();
  }
}
```

