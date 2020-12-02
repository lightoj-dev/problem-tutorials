# 1014 - Ifter Party

_You have given `T` test cases and for each test case you have `P`, number of piaju in the beginning, and `L` piaju left end of the day, find the value `Q`, the number of piaju's each of `C` contestant ate._

---

### Summary

This is a number theory problem and for the `T` group of the input set, where each set consists of `P` and `L` number, you have to find all the divisors of piaju's eaten or `(P-L)`.

### Solution

Initially, you had `P` amount of piaju's, and end of the day it became `L`, so piaju's eaten by the contestants are `(P-L)`. As `C` contestants were invited and each of them ate `Q` piaju's each, `P - L = C * Q` stands true. So the result will be all possible divisors of `Q`, the number of piaju's each contestant ate.

The algorithm is:

- find the number of piaju's eaten
- find all the unique divisors of the 'count of eaten piaju's'
- sort and print all the divisors in ascending order that satisfy `(L<Q)` condition.
- if no such solution exists print `impossible`.

### Code

#### C++

```cpp
    #include <bits/stdc++.h>

    using namespace std;

    int main(){
        #ifndef ONLINE_JUDGE
            freopen("in.txt","r",stdin);
            freopen("out.txt","w",stdout);
        #endif

        int tc,t(1);
        for(scanf("%d",&tc); tc; ++t,--tc){
            long long piaju,left;

            scanf("%lld%lld", &piaju,&left);

            // exception
            if(left*2>=piaju){
                printf("Case %d: impossible\n",t);
                continue;
            }

            printf("Case %d:",t);


            long long piajuEaten = piaju-left;
            // cout<<piajuEaten<<endl;

            vector<long long> possibleValueOfQ;


           // find all the divisors of piajuEaten
            for(long long i=1; i*i<=piajuEaten; ++i)
                if(piajuEaten%i==0){
                    possibleValueOfQ.push_back(i);

                if(piaju/i!=i)
                    possibleValueOfQ.push_back(piajuEaten/i);
                }

            // sort the divisors to print the answer in ascending order
            sort(possibleValueOfQ.begin(), possibleValueOfQ.end());

            // print the divisors
            for(auto x: possibleValueOfQ)
                // if(x>left)
                    printf(" %lld",x);


            printf("\n");
        }

        return 0;
    }

```
