# LOJ 1305 - Area of a Parallelogram
A parallelogram is a quadrilateral with two pairs of parallel sides. See the picture below:

<p align = "center"><img src="1305problem"></p>

Now you are given the co ordinates of __A__, __B__ and __C__, you have to find the coordinates of __D__ and the area of the parallelogram. The orientation of __ABCD__ should be same as in the picture.


### Input

Input starts with an integer _T (≤ 1000)_, denoting the number of test cases.

Each case starts with a line containing six integers __A<sub>x</sub>, A<sub>y</sub>, B<sub>x</sub>, B<sub>y</sub>, C<sub>x</sub>, C<sub>y</sub>__ where __(A<sub>x</sub>, A<sub>y</sub>)__ denotes the coordinate of __A__, __(B<sub>x</sub>, B<sub>y</sub>)__ denotes the coordinate of __B__ and __(C<sub>x</sub>, C<sub>y</sub>)__ denotes the coordinate of __C__. Value of any coordinate lies in the range __[-1000, 1000]__. And you can assume that __A__, __B__ and __C__ will not be collinear.


### Output

For each case, print the case number and three integers where the first two should be the coordinate of __D__ and the third one should be the area of the parallelogram. A

## Solution

We know the area of a __Parallelogram__, `A = base * height`. 

We must keep in mind that even though __AB || X - Axis || CD__ in the given example of the question, it might not be the true for all __test cases__ since it is not mentioned to be true for each case. And thus, we will use __d = <SQRT>(A<sub>x</sub> - B<sub>x</sub>)<sup>2</sup> + (A<sub>y</sub> - B<sub>y</sub>)<sup>2</sup></SQRT>__ and find out the __coordinates__ from there.

D<sub>y</sub>We can easily find out the `height` and as well the `x-coordinate` by doing some simple calculation.

To find out the __D<sub>x</sub>:
```

```