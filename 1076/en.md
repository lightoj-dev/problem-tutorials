# # LOJ 1076 - Get the Containers

## Summary

Basically, The problem says, "You have m container and n vessel you have to fill those container with milk from those vessel."

You have to fill those container without dividing the vessel's milk, that means milk from same vessel cannot be poured into different containers. Also you have to maintain order to poured those milk.

## Tags

Binary Search, Divide and Conquer

## Resources
1. [Binary Search](https://www.hackerearth.com/practice/algorithms/searching/binary-search/tutorial/)
2. [Another Binary Search](https://www.geeksforgeeks.org/binary-search/)

## Solution

The vessel can hold minimum 0 and maximum 10<sup>6</sup> also the number of vessel upto 10<sup>3</sup>
So, the answer will be between 0 to 10<sup>9</sup>

Let's **Binary Search** on 0 to 10<sup>9</sup>;

### Sudocode

let's L = 0 and R = 10<sup>9</sup>

then M is the container size. **[M = L + (R-L)/2]**

If M is the maximum size of those containers. Then, We have to count how many containers we need to pour with all of those milk.

1. if any of vessel size is bigger than the M then L = M+1 
  
    ##### After that count the number of container
2. if(number_of_container > m) L = M+1;     *[Here m is the number of container we can use (given in the problem)]*
3. else R = M 
4. if(L == R) then the ans is L;


## Code 

```C++

#include<bits/stdc++.h>
using namespace std;
int cas = 0;
void solve()
{
	cout << "Case "<< ++cas << ": ";
	int n,m;
	cin >> n >> m;
	vector<int>a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
   	/**Starting Binary Search**/
	int L = 0;
	int ans;
	int R = INT_MAX/2;
	while(L < R){
		int M = L + (R-L)/2;
		int cnt = 0,sum = 0;
        	bool ok = true;
		for(int i = 0; i < n; i++){
			if(a[i] > M){      //1st condition of binary search
				L = M+1;
               			ok = false;
				break;
			}
            		/**Counting the number of containner we need**/
			
			sum += a[i];      // sum is how much we fill of a M size containner
			if(sum == M){
				sum = 0;
				cnt++;     //cnt is the number of containner
			}
			else if(sum > M){
				cnt++;
				sum = a[i];
			}
		}
        	if(!ok)continue;  // if any of vessel is greater than M
		
		if(sum) cnt++;
		
		if(cnt > m){      //2nd condition
			L = M+1;
		}
		else {          //3rd Condition
			R = M;
		}
        ans = M;
        if(L == R) ans = L;
	}
    /**Ending the binary search part**/
	cout << ans << "\n";

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)solve();
	return 0;
}
```
