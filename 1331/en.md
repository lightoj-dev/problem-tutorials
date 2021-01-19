# LOJ 1331 - Agent J

## Summary

In this problem, you have to find following area of 3 circle if they ar enclosed with each other 
## Hint

if you connect 3 center circle by line, a Tringle is form. Determine the area of circle and then minus the area of 3 sector of each circle

- Prerequisites-1 : Area of a sector of a circle
- Prerequisites-2 : Area of tringle if 3 sides given
- Prerequisites-3 : angle if 3 sides given

# Solution
## Approach

A method for calculating the area of a triangle when you know the lengths of all three sides.

Let a,b,c be the lengths of the sides of a triangle. The area is given by:

\\[ Area =  \sqrt{s(s-a)(s-b)(s-c)}  \\] <br>
where,
\\[ s = (a+b+c) \over 2  \\]
<br>

Find the angle of each vertex of the triangle by the following formula




  


- Time Complexity: `O(1)` per test case.
- Memory Complexity: `O(1)` per test case.

## Code
### C++

```cpp


#include <bits/stdc++.h>
using namespace std ;

double area(double r , double angle)
{
    return 0.5*r*r*angle ;
}

double angle(double a, double b, double c)
{
    return acos( ( (b*b)+(c*c)-(a*a) ) / (2*b*c) ) ;
}


void _main_main()
{
    double a,b,c ;
    cin >> a >> b >> c ;

    double s = (a+a+b+b+c+c)/2.0 ;
    double total_area =  sqrt(s*(s-a-b)*(s-b-c)*(s-c-a)) ;

    total_area-= area(a,angle(b+c,c+a,a+b)) ;
    total_area-= area(b,angle(c+a,a+b,b+c)) ;
    total_area-= area(c,angle(a+b,b+c,c+a)) ;

    cout << fixed << setprecision(10) << total_area << "\n" ;

}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCase = 1 ; cin >> testCase ;
    for (int i = 0; i < testCase; i++){
        cout << "Case " << i+1 << ": " ;
        _main_main() ;
    }
        
}




```

Happy Coding!

Written by: [Moontasir Mahmood](https://www.linkedin.com/in/munmud/)