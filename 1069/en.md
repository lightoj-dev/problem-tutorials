# LOJ 1069 - Lift

**[Problem](http://lightoj.com/volume_showproblem.php?problem=1069):** You are given what floor you are on and what floor the lift is on. You need to calculate how many **seconds you will need to get to ground floor**.

_Assume that it takes 4 seconds for the lift to go from any floor to its adjacent floor (up or down). It takes 3 seconds to open or close the door of the lift and you need 5 seconds to enter or exit the lift._

That means you need to calculate the total time, T = time needed by the lift to come to your floor + time needed by the lift door to open + time needed by you to enter the lift  + time needed by the lift door to close + time needed by the lift to reach ground floor + time needed by the lift door to open again + time needed by you to exit the lift.

Here, 
- time needed by the lift to come to your floor = abs(myPosition-liftPosition) * 4sec

- time needed by the lift door to open = 3sec

- time needed by you to enter the lift = 5sec

-  time needed by lift door to close = 3sec

-  time needed by the lift to reach ground floor = myPosition * 4sec

- time needed by the lift door to open again = 3sec

- time needed by you to exit the lift = 5sec



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
      
        int timeTakenByMeToEnter= 5;
        int timeTakenByMeToExit= 5;
        int timeTakenByLiftToOpen= 3;
        int timeTakenByLiftToClose= 3;
        int timeTakenByLiftToReachMyFloor= abs(myPosition-liftPosition)*4; // If lift was on floor 7 and I was on floor 2, number of floors passed by the lift would be (2-7)=-5. But number of floors cannot be negative. To avoid the minus sign, we used the abs() function. As the lift takes 4 seconds to reach the adjacent floor, we multiply by 4.
        int timeTakenByLiftToReachGroundFloorFromMyFloor= (myPosition)*4; // Lift takes 4 seconds to go from one floor to the next floor. That's why we multiply by 4.
        
        int ans = timeTakenByLiftToReachMyFloor + timeTakenByLiftToOpen + timeTakenByMeToEnter + timeTakenByLiftToClose + timeTakenByLiftToReachGroundFloorFromMyFloor + timeTakenByLiftToOpen + timeTakenByMeToExit;
        
        cout<<"Case "<<t<<": "<< ans <<endl;
    }
}
```

### Java
-----
```java
package com.loj.volume;

import java.util.Scanner;

class Lift {
  public static void main(String[] args) throws Exception {
    Scanner scanner = new Scanner(System.in);
    int cases = scanner.nextInt();
    for (int caseno = 1; caseno <= cases; ++caseno) {
      int myPosition = scanner.nextInt();
      int liftPosition = scanner.nextInt();

      int timeTakenByMeToEnter= 5;
      int timeTakenByMeToExit= 5;
      int timeTakenByLiftToOpen= 3;
      int timeTakenByLiftToClose= 3;
      int timeTakenByLiftToReachMyFloor= Math.abs(myPosition-liftPosition)*4; // If lift was on floor 7 and I was on floor 2, number of floors passed by the lift would be (2-7)=-5. But number of floors cannot be negative. To avoid the minus sign, we used the abs() function. As the lift takes 4 seconds to reach the adjacent floor, we multiply by 4.
      int timeTakenByLiftToReachGroundFloorFromMyFloor= (myPosition)*4; // Lift takes 4 seconds to go from one floor to the next floor. That's why we multiply by 4.

      int ans = timeTakenByLiftToReachMyFloor + timeTakenByLiftToOpen + timeTakenByMeToEnter + timeTakenByLiftToClose + timeTakenByLiftToReachGroundFloorFromMyFloor + timeTakenByLiftToOpen + timeTakenByMeToExit;
   
      System.out.println("Case " + caseno + ": " + ans);
    }
  }
}
```
Happy Coding!

Written by: [Md. Arfaqur Rahman](https://www.facebook.com/arfaqur.rahman.31/)
