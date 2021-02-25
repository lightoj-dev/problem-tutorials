# Light OJ - 1003 : Drunk
---

### প্রবলেম সারমর্ম  
---
এই প্রবলেমে,
- তোমার কাজ হলো মাতাল হওয়া সম্ভব কিনা বের করা।
- মাতাল হবার জন্য **m** টি পূর্বশর্ত পূরণ করতে হবে।
- প্রতিটি পূর্বশর্তে, তোমাকে ২ টি ড্রিঙ্ক **a** এবং **b** দেয়া হবে।  মাতাল হবার জন্য তোমাকে **b** এর আগে **a** পান করতে হবে।
- এখন মাতাল হবার জন্য তোমাকে অবশ্যই সব পূর্বশর্ত মেনে সব ড্রিঙ্ক পান করতে হবে। 

### হিন্ট
---
কোন কোন কেইস এ তুমি মাতাল হতে পারবে না এটা চিন্তা করো।

### মূল ধারণা
---
পূর্বশর্ত যদি বলে:
```html
তোমার <soda>  এর আগে  <wine>
     <wine> এর আগে  <water> এবং
     <water>  এর আগে  <soda> খেতে হবে।
```
<img src="https://github.com/codermehraj/problem-tutorials/blob/main/1003/relation.png?raw=true" width="35%" height="30%"> <br>
তাহলে তা সম্ভব হবে না কারন তা একটি cycle তৈরি করবে এবং একসাথে সবগুলো পূর্বশর্ত মানতে পারবে না। অর্থাৎ বলা যায় যে, মাতাল হবার জন্য পূর্বশর্তে কোনো cycle থাকতে পারবে না। 

### পূর্ণাঙ্গ সমাধান
---
সুতরাং, আমাদের যা করা দরকার তা হলো -
- সবগুলো পূর্বশর্ত নিয়ে একটি graph তৈরি করতে হবে এবং তা সংরক্ষন করতে হবে।
- তারপরে **DFS** এলগোরিদম ব্যবহার করে graph টি visit করতে হবে এবং এর মাঝে color করতে হবে।
- যখনি আমরা color ব্যবহার করে cycle পাবো, তখনি আমরা সব কাজ বন্ধ করে দেবো এবং বলবো যে মাতাল হওয়া সম্ভব নয়।
- তাছাড়া, মাতাল হওয়া সম্ভব।

# কোড

### সি++
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
[মোঃ মেহরাজুল ইসলাম](https://lightoj.com/user/codermehraj)
