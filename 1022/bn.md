# ক্যাটাগরি : জ্যামিতি 

### প্রশ্নে কি জিজ্ঞেস করেছে ? 

প্রশ্নে একটি বর্গ দেয়া  থাকবে এবং এর ভিতরে একটি বৃত্ত এমন ভাবে রাখা হবে যেন বৃত্ত টি বর্গের চার বাহুকে স্পর্শ করে । আমাদের কে বৃত্ত দ্বারা আবৃত্ত নয় কিন্তু বর্গের ভিতরে এরকম এলাকার 
ক্ষেত্রফল  বের করতে হবে 

### যা যা শিখা উচিত এইটা করার আগে : 
১ [বৃত্তের ক্ষেত্রফল   ](https://www.khanacademy.org/math/cc-seventh-grade-math/cc-7th-geometry/cc-7th-area-circumference/v/area-of-a-circle ) 
২ [বর্গের ক্ষেত্রফল ] (https://www.khanacademy.org/math/geometry-home/geometry-area-perimeter/geometry-perimeter/v/perimeter-and-area-basics) 

## সমাধান 

### বৃত্তের ক্ষেত্রফল কে আমরা সবুজ অঞ্চল দিয়ে দেখালাম 
![alt text](https://user-images.githubusercontent.com/72943111/204069997-194fa2dc-d3b4-48ae-8444-7ac5b62d0e58.png)

### বর্গের  ক্ষেত্রফল কে আমরা লাল  অঞ্চল দিয়ে দেখালাম 
![alt text](https://user-images.githubusercontent.com/72943111/204070016-f4d87f3c-230c-43ed-bbcb-2e02329492fd.png)

### বৃত্ত কে বর্গের উপরে রাখলে দৃশ্যমান লাল অঞ্চলের ক্ষেত্রফল বের করতে হবে 
![alt text](https://user-images.githubusercontent.com/72943111/204070010-bfcaab02-e089-4357-85cf-edeba2d2091a.png)

ধাপ -১ বর্গের ক্ষেত্রফল বের করি (ধরি a) 
ধাপ -২ বৃত্তের ক্ষেত্রফল বের করি (ধরি b) 
ধাপ -৩ a - b ই হল আমাদের কাঙ্ক্ষিত এলাকা যা চিত্রের মাঝে সহজে ই বোঝা যাচ্ছে 

## কিছু সতর্কতা 
double ডাটা টাইপ নিয়ে কাজ করতে হবে |
উত্তর প্রদর্শনের সময় ০.০০০০০০০০০৯ যোগ করতে হবে ( যদিও এইটা ছাড়া ACC পাওয়া যায় )  

## সি ++ কোড 
```
#include<bits/stdc++.h>
using namespace std;
#define me boss
#define ll long long int
#define pi 2*acos(0.0)
int main()
{
    int tes=1,t;
    cin>>t;
    while(t--)
    {
        double a,b;
        cin>>a;
        b=a*2;
        printf("Case %d: %0.2lf\n",tes++,b*b-pi*a*a+0.000000009);
    }
return 0;
}

```



