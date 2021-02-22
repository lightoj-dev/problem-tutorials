# Light OJ - 1003 : Drunk
---

### Problem Summary 
---
In this problem,
- Your goal is to find out if it is possible to get drunk.
- To get drunk you will have to maintain **m** prerequisites.
- In each prerequisite, You will be given two drinks **a** and **b**. To get drunk succcessfully you have to take **a** before having **b**.
- Now, to get drunk, You must take all the drinks and also by maintaining all the prereqisites.

### Hint
---
Try to think in which case you will not be able to get drunk.

### Main Idea
---
If the prerequisite says that:
```html
You have take <soda> before <wine> and also
<wine> before <soda> ~ then it will not be possible.
```

### Detailed Solution
---
So, we what we need to do is:
- Make two lists and store **preDrink** and **postDrink**.
- Then we need to search for **(a,b)** and **(b,a)** pairs.
- For **i***th* and **j***th* prerequisite if  ```preDrink[i] == postDrink[j] && preDrink[j] == postDrink[i]```  is true then we can say that we found two pairs like  `(a,b) and (b,a)`.
- So, We will search for the above condition and if we find two pairs like that then we can say that is is not possible to get drunk. 
- Otherwise it is possible to get drunk.

# Code

### C++
```cpp
int main()
{
    int t; // number of testcases
	int cs = 1; // variable for printing the case number
	string a, b; // one must have "a" before having "b".
	cin >> t;
	while(t--){
		int m; // number of prerequisites 
		bool isDrunk = true; // assuming its possible to get drunk
		cin >> m;
		vector < string > preDrink(m), postDrink(m); // list of prerequisites 
		for(int i=0; i < m; i++)
			cin >> preDrink[i] >> postDrink[i];
		for(int i=0;i<m;i++){
			for(int j=i+1;j<m;j++){
				if(preDrink[i] == postDrink[j] && 
					preDrink[j] == postDrink[i]){
					isDrunk = false; // being drunk is not possible
					break;
				}
			}
		}
		if(isDrunk) cout << "Case " << cs++ << ": Yes\n";
		else cout << "Case " << cs++ << ": No\n";
	}
    return 0;
}
```

Written by:
[Md. Mehrajul Islam](https://github.com/codermehraj)
