# LOJ 1036 - A Refining Company

---
Tags : Dynamic Programming, Best Cumulative Sum, Memoization

The problem statement has these key points:

1. Conveyor belts moving row-wise in the same column from block __b__ to the __radium refinery__ can be added up as long as there is no column-wise conveyor belt moving in between them.
2. Conveyor belts moving column-wise in the same row from block __b__ to the __uranium__ can be added up as long as there is no row-wise conveyor belt moving in between them.
3. Any kind of conveyor is NOT _bi-directional_ when it comes to collection. It has to reach the refinery, in one direction. Either from East to West or from North to South, BUT West to East or South to North is not possible as the refineries’ placement is already given. This plays a heavy role in how to implement and memoize row-wise (left-to-right or right-to-left?) and column-wise (up-to-down or down-to-up?).

We need to find the max possible cumulative sum that can be reached by abiding by the above-mentioned rules.

### Helpful Resources

* [Memoization - WikiPedia](https://en.wikipedia.org/wiki/Memoization "Memoization - WikiPedia")

* [Memoization (1D, 2D and 3D) - GeeksForGeeks](https://www.geeksforgeeks.org/memoization-1d-2d-and-3d/ "Memoization (1D, 2D and 3D)")

* [What is Dynamic Programming ? - educative.io](https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews/m2G1pAq0OO0 "[What is Dynamic Programming?")

## Solution

For convenience, we will be using 2 separate 2D array-based matrices (use anything to create a grid as long as the `mutation` and `look up` cost is O(1)) to keep column-wise and row-wise cumulative sum respectively. We add one extra padding in both row and column for memoization purposes than the actual matrix size. Taking point `3` in account, to avoid another iteration through row-wise or column-wise, we will simply sum up value of previous block (in case of `row` : `matrix[row][column-1]` {left block}; and in case of `column` : `matrix[row-1][column]` {upper block}) and add it to current block value. We have cumulated both of the refinery matrices in such a way that the alternative refinery wasn't considered at all when cumulating a particular one

IF the problem stated the uranium refinery was at right and the radium refinery was at bottom, (i) we could have populated the matrices using ending indices {`i = m, i--` and `j = n, j--`} meaning taking inputs while transposing the matrices, __OR__, (ii) memoized the rows from `matrix[row][column+1]` {right block} and the columns from `matrix[row+1][column]` {lower block}. In any case, the implementation of the memoization direction would vary. How this is important or relevant is clarified in the next section when we are populating the result matrix, `memoizationMatrix`.

Let's take `test case 2` as an example.

`uraniumMatrix` :
|   i\j| 0  |1   |2   |3   |
|---|---|---|---|---|
|   __0__|0   |0   |0   |0   |
|   __1__|  0 |5   |15   |49   |
|   __2__ |   0|  0 |0   |0   |
|   __Total Uranium Taken From The Column </br> (M<sub>0</sub>,<sub>j</sub> + M<sub>1</sub>,<sub>j</sub> + ... + M<sub>n</sub>,<sub>j</sub>)__ | __0__ |  __5__ |__15__   |__49__   |

`radiumMatrix` :
|   i\j| 0  |1   |2   |3   |Total Radium Taken From The Row </br> (M<sub>i</sub>,<sub>0</sub> + M<sub>i</sub>,<sub>1</sub> + ... + M<sub>i</sub>,<sub>n</sub>) |
|---|---|---|---|---|---|
|   __0__|0   |0   |0   |0   | __0__|
|   __1__|  0 |0   |0   |0   | __0__|
|   __2__|   50|  0 |0   |0   | __50__|

Now for the block-wise decision-making of which type of conveyor it should be part of, we have a third 2D array that will compare both the uranium and radium matrices. Since `uraniumMatrix` was left to right cumulated, we need to add up from the upper block of the `memoizationMatrix` of the current block. From which resource the best cumulation was taken for that upper block is not relevant as we had cumulated the refinery matrices in the opposite direction of the refineries, thus cross-paths have been handled. To intuitively understand this, look at the last row of the `uraniumMatrix`, if we sum up neighboring blocks of the same column of the `uraniumMatrix`, we are calculating how much uranium was taken up to that particular column. As we are to choose the best, we are taking the updated value from `memoizationMatrix`. In other words, the `memoizationMatrix` works as the updated value holder for summing up. Similarly, it’s the immediate left block for adding to `radiumMatrix` as it memoized from up to down. Basically, `memoizationMatrix[i][j]` is the modified value for `uraniumMatrix[i][j]` and `radiumMatrix[i][j]`. And we are progressing as if we are comparing just 2 matrices. This is how we are doing the bottom-up approach. And the last block of the `memoizationMatrix` will be the answer.

`memoizationMatrix` :
|   i\j| 0  |1   |2   |3   |
|---|---|---|---|---|
|   __0__|0   |0   |0   |0   |
|   __1__|0 |5   |15   |49   |
|   __2__|   0|  50 |50   |__50__   |

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
    
    private static int findMax(int a, int b){
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
                - Treat this as the actual matrix for cumulation from previous block
            */
            for(int i = 1; i <= m; i++)
                for(int j = 1; j <= n; j++)
                    memoizationMatrix[i][j] = findMax(
                        memoizationMatrix[i-1][j] + uraniumMatrix[i][j], 
                        memoizationMatrix[i][j-1] + radiumMatrix[i][j]); 
            
            System.out.println(String.format("Case %s: %s",testCase ,memoizationMatrix[m][n]));
        }
    }
}
```
