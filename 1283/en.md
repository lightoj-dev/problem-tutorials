## LOJ-1283-Shelving Books
The problem asks us to put as many books as possible according to their height in ascending order from **n** books. We have to consider the books one by one from left to right. We may skip one or more books. And if the height of a book is greater than or equal than the last added book to the left **and** less than or equal to the last added book to the right, we can include the book in the shelf. For including the book, we have two options: add the book to the left or add it to the right. We use Dynamic Programming to find the best result. 

The statement for the problem says that the height of the books can be in range **[1,10⁵]**. As **1 <=n <= 100**, we can notice that there can be at most 100 distinct heights of the books. So, we can map the heights according to their magnitude. Then all the mapped heights will be within the range **[1,100]**. Now, our function for DP can have 3 states. One state is for the index of the books. One state is for the height of the last added book to the left and another state is for the height of the last added book to the right. For each book, can skip the book or if the book fulfils the condition, then we can add the book to the left or to the right. 
### C++ code
```cpp
#include "bits/stdc++.h"
 
using namespace std;
using ll = long long;

int book[100], hashed_book[100], n, memo[100][101][102];
map<int,int> rec;
set<int> con;

int dp(int i,int a,int b){
	if(i == n) return 0;
	if(memo[i][a][b] == -1){
		int ans = dp(i+1,a,b);        // skipping the current book. 
		if(hashed_book[i] >= a && b >= hashed_book[i]){
		    ans = max(ans,max(dp(i+1,hashed_book[i],b),dp(i+1,a,hashed_book[i]))+1); 
		    //including the current book.
	    }
		memo[i][a][b] = ans;
	}
	return memo[i][a][b];
}

int main(){  
    int T,s; cin>>T;
    for(int t = 1; t <= T; t++){
    	cin>>n;
    	s = 0;
    	rec.clear(); con.clear();
    	for(int i = 0; i < n; i++){
    		cin>>book[i];
    		con.insert(book[i]);                    // saving the heights in a set to find the distinct heights. 
    	}
    	for(int r: con) if(!rec.count(r)) rec[r] = ++s;    // mapping the heights.
    	for(int i = 0; i < n; i++) hashed_book[i] = rec[book[i]];   // creating a new array with the mapped heights. 
    	memset(memo,-1,sizeof(memo));
    	ll ans = dp(0,0,101);
    	cout<<"Case "<<t<<": "<<ans<<"\n";
    }
    return 0;
}
```

**Note**: For the base case, 0 and 101 are used as the last added height of the book to the left and to the right, as a result any height within the range **[1,100]** will be considered valid. 