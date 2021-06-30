# LOJ 1016 - Brush (II)
---
Tags : Sorting algorithms, Cartesian coordinate system

Given the `co-ordinates` of dust points, we need to find out how many `moves` we will need to clean all of them if we can sweep along the x-axis from any point to any point in just `1` move. Any point along the way that's within the width of the brush gets cleaned.

### Helpful Resources
* [Cartesian coordinate system - WikiPedia](https://en.wikipedia.org/wiki/Cartesian_coordinate_system "WikiPedia")

* [Sorting - WikiPedia](https://en.wikipedia.org/wiki/Sorting "WikiPedia")

* [Quick Sort - GeeksForGeeks](https://www.geeksforgeeks.org/quick-sort/ "GeeksForGeeks")

* [Quick Sort - HackerRank (Video)](https://www.youtube.com/watch?v=SLauY6PpjW4 "HackerRank")

* [Merge Sort - GeeksForGeeks](https://www.geeksforgeeks.org/merge-sort/ "GeeksForGeeks")

* [Merge Sort - HackerRank (Video)](https://www.youtube.com/watch?v=JSceec-wEyw "HackerRank")


## Solution
This is an implementation problem. We can solve it anyway we want to but ultimately we need a sorted list of `Y-coordinates`. We could have also use data structures of our preferred language that keep inputs in a sorted manner if we don't want to sort manually/through built-in methods. The point is, we need to sort the inputs for `Y-axis` of each of the point.

Any dust point that is within the width range of the brush (`W`) gets cleaned when cleaning in a certain `Y-height`. So, if we just sort the `Y-coordinate`s of the dust points, we can get rid of multiple dust points in the certain range of `[height,(height + width)]`. The idea is to keep sweeping until no new point is found of which `Y-Coordinate` is __not__ `[Current Move's Starpoint's Y coordinate, (Current Move's Starpoint's Y coordinate + Brush's width)]` inclusive. If a new point that is not inclusive in the range, we just increment the number of `moves`. And make a new inclusive range for that point again. For clarification:
```
Ycoordinates = {100,3,131,5,99}
Brush width = 3
Sort(Ycoordinates) = {3,5,99,100,131}

1st inclusive range
= [Sort(Ycoordinates)'s 1st element,
   (Sort(Ycoordinates)'s 1st element
    + Brush's width)
  ]
= [3,3+3] = [3,6]

Up to 5, {3,5} falls in the inclusive range [3,6]

Next inclusive range
= [Which element did not meet the last inclusive range
   (Which element did not meet the last inclusive range +Brushe's width)]
= [99,102]
So, {99,100} will be covered now.

We keep going like this and increment the inclusive range and number of moves each time.

```
The above implementation is `accepted`.



## Solution in C++


```cpp
#include <bits/stdc++.h>


using namespace std;

// A generic slave method of quickSort(); nothing to tweak
int partition(int array[], int leftIndex, int rightIndex){
    int pivotValue = array[rightIndex];
    int toBePivotIndex = (leftIndex - 1);
    for(int comparisonIndex = leftIndex; comparisonIndex <= rightIndex - 1; comparisonIndex++){
        if (
            // We are sorting in ascending order
            array[comparisonIndex] < pivotValue
        ) {
            // Take the bigger value to the right
            toBePivotIndex++;
            int temp = array[toBePivotIndex];
            array[toBePivotIndex] = array[comparisonIndex];
            array[comparisonIndex] = temp;
        }
    }
    // Take the pivot value in the correct position
    int temp = array[toBePivotIndex+1];
    array[toBePivotIndex+1] = array[rightIndex];
    array[rightIndex] = temp;

    return (toBePivotIndex + 1); // new pivot point
}

// A generic quickSort() method; nothing to tweak
void quickSort(int array[], int leftIndex, int rightIndex){
    // Pivot point can be chosen arbitarily; implement accordingly
    if (leftIndex < rightIndex) {
        int partitionIndex = partition(array, leftIndex, rightIndex);
        quickSort(array, leftIndex, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, rightIndex);
    }
}


int main(){
    // Enable fast I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases,numberOfDustPoints,widthOfBrush,xCoordinate,yCoordinate;

    cin >> testCases;

    for(int testCase = 1; testCase <= testCases; testCase++){
        int numberOfMoves = 0;
        cin >> numberOfDustPoints >> widthOfBrush;
        int dustPointsYCoordinates[numberOfDustPoints];

        for(int i = 0; i < numberOfDustPoints; i++){
            cin >> xCoordinate >> yCoordinate;
            dustPointsYCoordinates[i] = yCoordinate;
        }
        // Sort the array
        quickSort(dustPointsYCoordinates,0, numberOfDustPoints-1);

        // Start sweeping from the lowest point
        int currentBrushYCoordinate = dustPointsYCoordinates[0];
        numberOfMoves++;

        for (int i = 0; i < numberOfDustPoints; i++) {
	    if(currentBrushYCoordinate + widthOfBrush < dustPointsYCoordinates[i]) {
		currentBrushYCoordinate = dustPointsYCoordinates[i];
		numberOfMoves++;
	    }

	}
        cout << "Case " << testCase << ": " << numberOfMoves << '\n';
    }

    return 0;
}
```
