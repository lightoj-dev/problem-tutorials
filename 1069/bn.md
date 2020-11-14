# LOJ 1069 - Lift

**[Problem](http://lightoj.com/volume_showproblem.php?problem=1069):** তুমি কততম ফ্লোরে অবস্থান করছ আর লিফট কততম ফ্লোরে আছে তা ইনপুট হিসেবে দেয়া হবে। **একতলায় যেতে তোমার কত সেকেন্ড প্রয়োজন হবে** তা নির্ণয় কর।

_ধরে নাও, এক ফ্লোর থেকে অন্য ফ্লোরে (উপরে বা নিচে) যেতে লিফটের &nbsp;4 সেকেন্ড সময় লাগে। লিফটের দরজা বন্ধ হতে বা খুলতে &nbsp;3 সেকেন্ড সময় লাগে এবং তোমার লিফটে প্রবেশ করতে বা লিফট থেকে বের হতে &nbsp;5 সেকেন্ড সময় লাগে।._

তাহলে, তোমার নির্ণয় করতে হবে মোট সময়, T = অন্য ফ্লোর থেকে তোমার ফ্লোরে লিফট আসতে প্রয়োজনীয় সময় + লিফটের দরজা খুলতে প্রয়োজনীয় সময় + তোমার লিফটের দরজা দিয়ে প্রবেশ করতে প্রয়োজনীয় সময়  + লিফটের দরজা বন্ধ হতে প্রয়োজনীয় সময় + লিফটের তোমার ফ্লোর থেকে প্রথম ফ্লোরে যেতে প্রয়োজনীয় সময় + একতলায় লিফট পৌছানোর পর দরজা খুলতে প্রয়োজনীয় সময় + তোমার লিফট থেকে বের হতে প্রয়োজনীয় সময় 

এ্খানে, 
- অন্য ফ্লোর থেকে তোমার ফ্লোরে লিফট আসতে সময় লাগে = abs(myPosition-liftPosition) * 4sec

- লিফটের দরজা খুলতে সময় লাগে = 3sec

- তোমার লিফটে প্রবেশ করতে সময় লাগে = 5sec

-  লিফটের দরজা বন্ধ হতে সময় লাগে = 3sec

-  প্রথম ফ্লোরে পৌছাতে লিফটের সময় লাগে = myPosition * 4sec

- প্রথম ফ্লোরে পৌছানোর পর লিফটের দরজা খুলতে সময় লাগে = 3sec

- লিফট থেকে বের হতে তোমার সময় লাগে = 5sec



### C++
-----
```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
    int testcase; 
    cin>>testcase;
    
    for(int t=1; t<=testcase; t++){
        int myPosition, liftPosition;
        cin>>myPosition>>liftPosition;
      
        int timeTakenByMeToEnter=5;
        int timeTakenByMeToExit=5;
        int timeTakenByLiftToOpen=3;
        int timeTakenByLiftToClose=3;
        int timeTakenByLiftToReachMyFloor= abs(myPosition-liftPosition)*4; // লিফট যদি 7 তলায় থাকত আর আমি দোতলায় থাকতাম, লিফটের অতিক্রান্ত ফ্লোরসংখ্যা = (2-7)= -5 । ফ্লোরসংখ্যা কখনো ঋণাত্বক হতে পারেনা। ঋণাত্বক মান এড়ানোর জন্য আমরা abs() function ব্যবহার করেছি। যেহেতু লিফটের এক ফ্লোর থেকে অন্য ফ্লোরে যেতে 4 সেকেন্ড লাগে, তাই 4 দিয়ে গুণ করা হয়েছে।
        int timeTakenByLiftToReachGroundFloorFromMyFloor=(myPosition)*4; // লিফট এক ফ্লোর থেকে অন্য ফ্লোরে যেতে 4 সেকেন্ড সময় নেয় বলে 4 দিয়ে গুণ করা হয়েছে।
        
        cout<<"Case "<<t<<": "<<  abs(myPosition-liftPosition)*4 + timeTakenByLiftToOpen + timeTakenByMeToEnter + timeTakenByLiftToClose + (myPosition)*4 + timeTakenByLiftToOpen + timeTakenByMeToExit<<endl;
    }
}
```
Happy Coding!
