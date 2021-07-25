# Problem Name: February 29
## [LightOj-1414](https://lightoj.com/problem/february-29) 
## Problem Idea:
In this problem, you will be given two different date which format is (Month Date, Year). You have to find the number of leap days in between them.<br>
**Note :** leap day means February 29.
## Solution Approach:
We know that leap year is a year which divisible by 4 but not divisible by 100  or which divisible by 400.<br>
For example:<br>
year= 2020<br>
First condition is, year%4==0 and year%100 !=0.<br>
Second condition is, year%400==0.<br>
Now, if any year accepts one or both of these conditions then we called this year is a leap year otherwise NOT a leap year.<br>

In this problem , count the number of leap days between the range .<br>
<details>
<summary>  
    Hint
</summary>
At first count the total number of leap year between of the range .then<br>
If  Starting Year of the range is a leap year but the Month already cross February so neglecting this leap year of the total number of leap year .<br>
If Ending Year of the range is a leap year but the Month and date are less than February 29 so neglecting this leap year of the total number of leap year.<br>
</details>

You know that a Leap comes after 4 Years later. So, find the number of Multiples of 4 between two ranges Dividing by 4. Then As you did for Checking Leap Year find the Multiples of 100. Further, find the Multiples of 400. Then apply the Rule given Below -<br>

Number of Leap Years = Multiples of 4 - Multiples of 100 + Multiples of 400. <br>
Where,<br>  

- Multiples of 4 = ( Ending Year - (Starting Year -1) ) /4 
- Multiples of 100 = ( Ending Year -( Starting Year - 1 ) ) /100 
- Multiples of 400 = ( Ending Year - (Starting Year -1 ) ) /400 


**Time Complexity: O(1)** per test_case;<br>

## Cpp Code:
```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{

	int test_case;
	cin >> test_case;
	string start_month, end_month;
	char comma;
	int start_date, end_date, start_year, end_year;
	for (int i = 1; i <= test_case; i++)
	{
		cin >> start_month >> start_date >> comma >> start_year;
		cin >> end_month >> end_date >> comma >> end_year;
		if (start_month == "January" or start_month == "February") start_year = start_year;
		else start_year++;

		if (end_month == "January" or (end_month == "February" and end_date < 29)) end_year--;
		else end_year = end_year;
		
		int mul_of_4 = end_year / 4 - (start_year - 1) / 4;
		int mul_of_400 = end_year / 400 - (start_year - 1) / 400;
		int mul_of_100 = end_year / 100 - (start_year - 1) / 100;

		int total = mul_of_4 + mul_of_400 - mul_of_100;
		cout << "Case "<<i<<": "<<total << endl;
	}
}

```
## Python Code:
```python

import calendar
month={"January":0, "February":1, "March":2, "April":3, "May":4, "June":5, "July":6, "August":7, "September":8, "October":9, "November":10, "December":11}
for i in range(1,int(input())+1):
	start=list(input().split())
	end=list(input().split())
	year=calendar.leapdays(int(start[2]),int(end[2])+1)
	end_date=end[1][:-1]
	if calendar.isleap(int(start[2]))==True and (month[start[0]]>1):
		year-=1
	if calendar.isleap(int(end[2]))==True and (month[end[0]]<1 or (month[end[0]]==1 and int(end_date)<=28)):
		year-=1
	print("Case {}:".format(i),year)
	
	
```
Happy Coding!

Written by: [Md. Rasel Meya](https://lightoj.com/user/rhrasel94)
