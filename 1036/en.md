# LOJ 1036 - A Refining Company

---
Tags: Dynamic Programming, Best Cumulative Sum, Memoization

The problem statement has these key points:

1. Conveyor belts moving up-down in the same column from block __b__ to the __radium refinery__ can be added up as long as there is no left-right conveyor belt moving in between them.
2. Conveyor belts moving left-right in the same row from block __b__ to the __uranium__ can be added up as long as there is no up-down conveyor belt moving in between them.
3. Any kind of conveyor is NOT _bi-directional_ when it comes to collection. It has to reach the refinery, in one direction. Either from right->left or from down->up, BUT left->right or up->down is not possible as the refineries’ placement is already given. This plays a heavy role in how to implement and memoize left-right (left->right or right->left?) and up-down (up->down or down->up?).

We need to find the maximum possible cumulative sum that can be reached by following the above-mentioned rules.

### Helpful Resources

* [Memoization - WikiPedia](https://en.wikipedia.org/wiki/Memoization "Memoization - Wikipedia")

* [Memoization (1D, 2D and 3D) - GeeksForGeeks](https://www.geeksforgeeks.org/memoization-1d-2d-and-3d/ "Memoization (1D, 2D and 3D)")

* [What is Dynamic Programming? - educative.io](https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews/m2G1pAq0OO0 "[What is Dynamic Programming?")

## Solution (Key Points)

There are 2 main sub-problems that we need to solve to get the final answer. They are:

1. What is the cumulation of each block resource variation-wise separately? We need this for comparison.
2. A block should be part of which type of conveyor? The actual decision-making part.

## 1. What is the cumulation of each block resource variation-wise separately?

For this just add up the immediately previous block’s value with the current block’s value according to the conveyor type while taking inputs.  Here the direction is important. We need to cumulative in the opposite direction of the refineries. Since the refineries are in left and up, cumulative in right and down direction. For `uraniumMatrix` it's `[row][column-1]` and for `radiumMatrix` it's `[row-1][column]`.

### Why does cumulation direction matter?

Compare the following 2 for a simple left-right cumulation.

Towards the refinery:

||0|1|2|3|
|---|---|---|---|---|
|0|<|<|^|x|

If we cumulate towards the refinery, the direction of cumulation will be `(0,3) -> (0,2) -> (0,1) -> (0,0)`. But `(0,2)` cuts the path. So both `(0,0)` and `(0,1)` is _faulty_ cumulated.

Opposite of the refinery:

||0|1|2|3|
|---|---|---|---|---|
|0|>|>|^|x|

In this case, `(0,0) -> (0,1) -> (0,2) -> (0,3)` is the direction. So `(0,0)`, `(0,1)` is still correctly cumulated even if `(0,2)` is going upwards.  

## 2. A block should be part of which type of conveyor?

While addressing subproblem-1, we did not take into account the alternative resource for any of the matrices. We just do a tweaked cumulation sum comparing these 2 matrices and take the best among them in a third matrix, `memoizationMatrix`.

### What are the cases for ultimate cumulation?

* Uranium is more: `memoizationMatrix[i-1][j] + uraniumMatrix[i][j]`.
* Radium is more: `memoizationMatrix[i][j-1] + radiumMatrix[i][j]`.

### How are we doing the ultimate cumulation (reason behind choosing between `memoizationMatrix[i-1][j] + uraniumMatrix[i][j]` or `memoizationMatrix[i][j-1] + radiumMatrix[i][j]`)?

||0|1|2|3|
|---|---|---|---|---|
|0|x|x|x|x|
|1|x|x|x|x|
|2|x|x|x|x|
|3|x|x|x|x|
|4|x|x|x|x|

Taking a look at the above, we need to know what is the ultimate cumulative sum of from `(0,0)` to `(2,3)` if we consider a block has been carrying the summation of its previous blocks either left-right (uranium/left-right) or up-down (radium/up-down)?

left-right:

||0|1|2|3|
|---|---|---|---|---|
|0|>|>|>|>|
|1|>|>|>|>|
|2|>|>|>|>|

{`>` is summed up with its value and the __IMMEDIATE__ previous block's value}

Here, `((0,3) + (1,3) + (2,3))` [this is up->down, look at the image] = ULTIMATE CUMULATIVE SUM. Because while __solving sub-problem-1__, we made sure `(0,3) = (0,0) + (0,1) + (0,2) + (0,3)`, `(1,3) = (1,0) + (1,1) + (1,2) + (1,3)` and `(2,3) = (2,0) + (2,1) + (2,2) + (2,3)`, which was adding left->right. But we need `sum(each cumulated block)`, which is __actually__ from up->down of the cumulated left-right blocks. Basically, __(M<sub>0</sub>,<sub>j</sub> + M<sub>1</sub>,<sub>j</sub> + ... + M<sub>n</sub>,<sub>j</sub>)__ is applicable for left-right ULTIMATE CUMULATIVE SUM for up to __M<sub>n</sub>,<sub>j</sub>__ block.

up-down:

||0|1|2|3|
|---|---|---|---|---|
|0|v|v|v|v|
|1|v|v|v|v|
|2|v|v|v|v|

{`v` is summed up with its value and the __IMMEDIATE__ previous block's value}

Similarly, here, `((2,0) + (2,1) + (2,2) + (2,3))` [this is left->right, look at the image] = ULTIMATE CUMULATIVE SUM. Because while __solving sub-problem-1__, we made sure `(2,0) = (0,0) + (1,0) + (2,0)`, `(2,1) = (0,1) + (1,1) + (2+1)`, `(2,2) = (0,2) + (1,2) + (2,2)` and `(2,3) = (0,3) + (1,3) + (2,3)`, which was adding up->down. But we need `sum(each cumulated block)`, which is __actually__ from left->right of the cumulated up->down blocks. Basically, __(M<sub>i</sub>,<sub>0</sub> + M<sub>i</sub>,<sub>1</sub> + ... + M<sub>i</sub>,<sub>n</sub>)__ is applicable for up-down ULTIMATE CUMULATIVE SUM for up to __M<sub>i</sub>,<sub>n</sub>__ block.

We have established how are we doing full matrix cumulation up to a certain block left-right or up-down wise.

Now for a matrix,

||0|1|2|3|
|---|---|---|---|---|
|0|x|x|x|x|
|1|x|x|x|x|
|2|x|x|x|x|
|3|x|x|x|x|
|4|x|x|x|x|

If `x` holds the updated value then we can easily apply any of the above-mentioned block-wise cumulations, and then compare, right? The 3rd matrix is required for that. That's why `memoizationMatrix[i-1][j]` is the replacement of `uraniumMatrix[i-1][j]` and `memoizationMatrix[i][j-1]` is the replacement of `radiumMatrix[i][j-1]` to apply the left-right and up-down ULTIMATE CUMULATION SUM respectively. And if we have the updated value, it becomes irrelevant how `x` was obtained because the ultimate goal is to carry out the maximum cumulative sum block by block until the last block is met. THE CROSS PATHS WERE ALREADY HANDLED IN SUB-PROBLEM 1.

### Why a 3rd Matrix and not just update the values of the original?

We can't over-write the original 2 matrices because while iterating, we can't be sure if there exists a single block of a particular conveyor that can outweigh the whole alternative conveyor up to that block.

The above implementation is `accepted`.

## Time Complexity

2D Array -> mutation : O(1)

2D Array -> look up : O(1)

Whole 2D Array -> iteration : O(row x column)

Overall Complexity : O(3 x row x column) = O(row x column)

## Solution in Java (Iterative)

* `Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));` will throw `TLE` or `MLE`.

```java
import java.io.DataInputStream;
import java.io.IOException;

/* 
The `Reader` class aids only in taking inputs. Use any alternative that satisfies the time and memory constraints.
https://www.geeksforgeeks.org/fast-io-in-java-in-competitive-programming/ - 4th implementation for fast Java I/O.
*/

class Reader {
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Reader() {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public int nextInt() throws IOException {
        int ret = 0;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');

        if (neg)
            return -ret;
        return ret;
    }

    private void fillBuffer() throws IOException {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1)
            buffer[0] = -1;
    }

    private byte read() throws IOException {
        if (bufferPointer == bytesRead)
            fillBuffer();
        return buffer[bufferPointer++];
    }

    public void close() throws IOException {
        if (din == null)
            return;
        din.close();
    }
}



public class Main{
    
     private static int FindMax(int a, int b){
        return a > b ? a : b;
    }
    
    public static void main(String[] args) throws IOException {
        Reader in = new Reader();
        int[][] radiumMatrix; // East to West.
        int[][] uraniumMatrix; // South to North.
        int[][] memoizationMatrix; // Result matrix and updated value holder.

        int testCases = in.nextInt();
        
        for(int testCase = 1; testCase <= testCases; testCase++){
            int m = in.nextInt();
            int n = in.nextInt();

            radiumMatrix = new int[m+1][n+1]; 
            uraniumMatrix = new int[m+1][n+1];
            memoizationMatrix = new int[m+1][n+1];
            
            // Input for Uranium
            for(int i = 1; i <= m; i++){
                for(int j = 1; j <= n; j++){
                    uraniumMatrix[i][j] = in.nextInt();

                    // East to West cumulative sum memoization
                    uraniumMatrix[i][j] += uraniumMatrix[i][j-1];
                }
            }

            // Input for Radium
            for(int i = 1; i <= m; i++){
                for(int j = 1; j <= n; j++){
                    radiumMatrix[i][j] = in.nextInt();

                    // South to North cumulative sum memoization
                    radiumMatrix[i][j] += radiumMatrix[i-1][j];
                }
            }
            
            /*Memoization Matrix
                - Treat this as the actual matrix for cumulation from the previous block
            */
            for(int i = 1; i <= m; i++)
                for(int j = 1; j <= n; j++)
                    memoizationMatrix[i][j] = FindMax(
                        memoizationMatrix[i-1][j] + uraniumMatrix[i][j], 
                        memoizationMatrix[i][j-1] + radiumMatrix[i][j]); 
            
            System.out.println(String.format("Case %s: %s",testCase ,memoizationMatrix[m][n]));
        }
    }
}
```
