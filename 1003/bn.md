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
পূর্বশর্ত যদি বলেে:
```html
তোমার <পেপসি> এর আগে <কোক> এবং 
<কোক> এর আগে <পেপসি> খেতে হবে ~ তাহলে তা সম্ভব হবে না।
```

### পূর্ণাঙ্গ সমাধান
---
সুতরাং, আমাদের যা করা দরকার তা হলো -
- **preDrink** এবং **postDrink** নামে ২ টি লিস্ট বানিয়ে আগের ও পরের ড্রিঙ্ক স্টোর করা
- তারপরে আমাদের এমন ২টি ড্রিঙ্ক পেয়ার বের করতে হবে যা (a,b) এবং (b,a) এর সমতুল্য।
- i তম এবং j তম পূর্বশর্ত এর জন্য় যদি ```preDrink[i] == postDrink[j] && preDrink[j] == postDrink[i]``` সত্য হয় তাহলে আমরা বলতে পারি যে আমরা (a,b) এবং (b,a) এর সমতূল্য ২ টি পেয়ার খুঁজে পেয়েছি। 
- তাই আমরা উপরের শর্ত মত পেয়ার খোঁজ করবো এবং যদি এমন কোনো পেয়ার পাই তাহলে আমরা বলতে পারি যে মাতাল হওয়া সম্ভব নয়।
- তাছাড়া, মাতাল হওয়া সম্ভব।

# কোড

### সি++
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
[মোঃ মেহরাজুল ইসলাম](https://github.com/codermehraj)
