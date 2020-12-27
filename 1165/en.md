
# LightOJ - 1165 - Digit Dancing



### Problem Summary

We are given 8 numbers(1-8) with a different sign. (+)value indicate male and (-)value indicate female. A dance can be happen between opposite sign value and by dancing one of them will change his position next to the other. We have to find minimum movement for sorting them in increasing order by neglecting their sign.


### Solution Idea

We will use generate hashmap from the 8 value sequence to a int (ex. 12345678) and use set to keep track of the found sequence. When generating hashMap we will also neglect the sign and assume + for every input. From a sequence we will generate all possible sequence and mark down new sequence. then we will use a queue to fing the minimum movement to get to destination (12345678)





### c++ Implementation
```

#include <bits/stdc++.h>
using namespace std;

#define FORN(i, n)              for(int i = 0; i < n; i++)
#define FORAB(i, a, b)          for(int i = a; i <= b; i++)
/*---------------------------------- x ------------------------------------*/


// a structure to indicate minimum movement for a sequence
struct data{
    int array[10] ;
    int distance ;
};

int ans ;
bool prime[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1}; // check if it is a prime
set <int> se ; // mark our previous sequence
queue <data> q ; 

/*
Find hashMap for a sequence like below :
sequence : 1 2 4 5 6 -7 -3 8
return hashMap : 12456738
*/
int getHashMap(int array [])
{
    int num =0 ;
    FORN(i,8) num = num * 10 + abs(array[i]) ;
    return num ;
}



void solution()
{

    // initialization / clear previous testcase data
    se.clear() ;
    while(!q.empty()) q.pop() ;

    data in ;
    FORN(i,8) cin >> in.array[i] ;
    in.distance = 0 ;

    if (getHashMap(in.array) == 12345678){
        ans = 0 ;
        return ;
    }
    
    q.push(in) ;
    se.insert(getHashMap(in.array)) ;

    while(!q.empty())
    {
        data prev = q.front(); q.pop() ;
        prev.distance++ ;


        //  we are checking the position i,j as if i can be place beside j 
        FORN(i,8) FORN(j,8)
        {
            if(i == j) continue ;
            if (prev.array[i]*prev.array[j] >0 || prime[(abs(prev.array[i])+abs(prev.array[j]) )] == 0) continue ;
            
            data now = prev ;
            if (i < j){
                FORAB(k,i,j-2) swap(now.array[k], now.array[k+1]) ;
                int temp = getHashMap(now.array) ;
                if (se.count(temp) == 0)
                {
                    if (temp == 12345678){
                        ans = now.distance ;
                        return ;
                    }
                    se.insert(temp) ;
                    q.push(now) ;
                }
                swap(now.array[j-1] , now.array[j]) ;
                temp = getHashMap(now.array) ;
                if (se.count(temp) == 0)
                {
                    if (temp == 12345678){
                        ans = now.distance ;
                        return ;
                    }
                    se.insert(temp) ;
                    q.push(now) ;
                }
            }
            else {
                for (int k = i ; k>j+1 ; k--) 
                    swap(now.array[k] , now.array[k-1]) ;
                int temp = getHashMap(now.array) ;
                if (se.find(temp) == se.end())
                {
                    if (temp == 12345678){
                        ans = now.distance ;
                        return ;
                    }
                    se.insert(temp) ;
                    q.push(now) ;
                }
                swap(now.array[j+1] , now.array[j]) ;
                temp = getHashMap(now.array) ;
                if (se.find(temp) == se.end())
                {
                    if (temp == 12345678){
                        ans = now.distance ;
                        return ;
                    }
                    se.insert(temp) ;
                    q.push(now) ;
                }
            }
            

        }

    }
}
int main ()
{
    int testCase = 1 ;cin >> testCase ;
    for (int i = 0; i < testCase; i++){

        cout << "Case " << i+1 << ": " ;
        ans = -1 ;
        solution() ;
        cout << ans << "\n" ;

    }
        
}

```
