# LOJ 1307 - Counting Triangles
## Discussion 
Here, given N sticks and we have to find all valid triangles, where  area  `R>0`. So, here naive solution is, we will iterate over all combination of three sticks and count the valid one.<br/>
so we need to write loop like this -
```C++
                        for(int i=0;i<n;i++){
                            for(int j=i+1;j<n;j++){
                                for(int k=j+1;k<n;k++){
                                    if( is_valid_triangle(arr[i] , arr[j] , arr[k]) == true )
                                           ans++;
                                }
                            }
                        }
```                        
So, the complexity of this solution is `O(n^3)`. But this solution will not pass. We are looking for `O(n^2* log n )`  solution.
***
## Solution Idea
First, we will sort the sticks in ascending order. We know that for a triangle (having a,b & c line segment, and area >0 ) any two line `a+b > c`. Now we will write 1st two for a loop as before (written above). this will fix 2 sticks. So as we have already fixed 2 sticks, we can `binary search` on the 3rd stick, and its length is less than `a+b`. Thus we can easily count the number of lines which are less than a+b.<br/>
For sorting, complexity = `n log n` ;<br/>
There are two nested for loop and a binary search inside them, so complexity = `n^2 * log n` 
So, the total complexity = `n log n + n^2 *log n`    =  `O(n^2* log n)` 

## Solution Code(C++)
```C++
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t,cs = 1;
    cin>>t;
    while(cs <= t){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum = arr[i] + arr[j]; //length of two line segment
                int ind = upper_bound(arr,arr+n,sum-1) - arr; //doing binary search on the third line segment
                ind--;
                if(ind > j){
                    ans += ind-j;
                }
 
            }
        }
        printf("Case %d: %d\n",cs,ans);
        cs++;
    }
    return 0;
}
```
