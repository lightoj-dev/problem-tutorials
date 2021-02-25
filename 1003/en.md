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
You have to take <soda> before <wine> ,
              <wine> brfore <water> also
              <water> before <soda>
```
<img src="https://github.com/codermehraj/problem-tutorials/blob/main/1003/relation.png?raw=true" width="400" height="350"> <br>
then it will not be possible because it creates a cycle of order and you cannot satisfy all the prerequisite in a cycle. So, You can only be drunk if the prereqisite do not create a cycle.

### Detailed Solution
---
So, we what we need to do is:
- Make a graph of dependencies and store them.
- Use **DFS** algorithm to visit the graph and color them accordingly on the way.
- Whenever you find a cycle using the colors close all the process and print it is not possible to get drunk.
- Otherwise it is possible to get drunk.

# Code

### C++
```cpp
// defining dfs colors
#define white 0 // not visited
#define gray 1  // processing 
#define black 2 // done processing


map < string , vector < string > > child; // to store the dependencies
map < string , int > colors; // to store the colors of the nodes
bool drunk; // tells if it can be drunk or not

void dfsCycleFinder(string parent){
	colors[parent] = gray; // started processing
	for(auto nodes : child[parent]){
		// white means not processed yet
		if(colors[nodes] == white) dfsCycleFinder(nodes);
		else if(colors[nodes] == gray){
			// gray to gray in a directed graph
			// which means it has a cycle
			// if it has a cycle one cannot be drunk
			drunk = false;
			return;
		}
	}
	// finished processing
	colors[parent] = black;
}

// returns true if it is possible to get drunk
bool isDrunk(){
	string a, b; // one must have "a" before having "b".
	int m; // number of prereqisite
	cin >> m;
	for(int i = 0 ; i < m ; i++ ){
		cin >> a >> b; // must have a before b
		child[a].push_back(b);
		colors[a] = colors[b] = white; // not visited

	}
	drunk = true; // assuming one can get drunk

	for(auto node: colors){
		if(node.second == white) dfsCycleFinder(node.first);
		if(!drunk) return false; // cannot get drunk
	}
	return true; // can get drunk
}
```

Written by:
[Md. Mehrajul Islam](https://lightoj.com/user/codermehraj)
