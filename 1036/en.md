# LOJ 1036 - A Refining Company

---
Tags : Dynamic Programming, Best Cummulative Sum, Memoization

The problem statement has these key points:

1. Conveyor belts moving row-wise in the same column from block __b__ to the __radium refinery__ can be added up as long as there is no column wise conveyor belt moving in between them.
2. Conveyor belts moving column-wise in the same row from block __b__ to the __uranium__ can be added up as long as there is no row wise conveyor belt moving in between them.
3. Any kind of conveyor is NOT _bi-directional_ when it comes to collection. It has to reach the refinery, in one direction. Either from East to West or from North to South, BUT West to East or South to North is not possible as the placement of the refineries are already given. This plays a heavy role on how to implement and memoize row-wise (left-to-right or right-to-left?) and column-wise (top-to-bottom or bottom-to-top?).

We need to find the max possible cummulative sum can be reached abiding by above mentioned rules.

### Helpful Resources

* [Memoization - WikiPedia](https://en.wikipedia.org/wiki/Memoization "Memoization - WikiPedia")

* [Memoization (1D, 2D and 3D) - GeeksForGeeks](https://www.geeksforgeeks.org/memoization-1d-2d-and-3d/ "Memoization (1D, 2D and 3D)")

* [What is Dynamic Programming ? - educative.io](https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews/m2G1pAq0OO0 "[What is Dynamic Programming?")

## Solution

For convenience, we will be using 2 seperate 2D array-based matrix (use anything to create a grid as long as the `mutation` and `look up` cost is O(1)) to keep column-wise and row-wise cummulative sum respectively. Taking point `3` in account, to avoid another iteration through row-wise or column-wise, we will simply sum up value of previous block (in case of `row` : `matrix[row][column-1]` {left block}; and incase of `column` : `matrix[row-1][column]` {upper block}) and add it to current block value. Let's take `test case 2` as an example.

uraniumMatrix
|   i\j| 0  |1   |2   |3   |
|---|---|---|---|---|
|   0|0   |0   |0   |0   |
|   1|  0 |5   |15   |49   |
|  2 |   0|  0 |0   |0   |

radiumMatrix
|   i\j| 0  |1   |2   |3   |
|---|---|---|---|---|
|   0|0   |0   |0   |0   |
|   1|  0 |0   |0   |0   |
|  2 |   50|  0 |0   |0   |

IF the problem stated the uranium refinery was at right or the radium refinery was at bottom, (i) we could have populated the matrices using ending indices {`i = m, i--` and `j = n, j--`} meaning taking inputs while transpoing the matrices, __OR__, (ii) memoized the rows from `matrix[row][column+1]` {right block} and the columns from `matrix[row+1][column]` {lower block}. How this is important or relevant is clarified in the next section when we are populating the result matrix, `memoizationMatrix`.

Now for the decision making, we have a third 2D array which will compare both from the uranium and radium matrices. We have column-wise memoized the radium matrix in such a way that the __downward__ blocks hold the cummulative sums of previous block, and in case of uranium, it is the __rightward__ blocks. When we choose to take radium then we can add to the left block, and if we choose to take uranium, we can add to the upper block of the `memoizationMatrix`. Since we are going towards the _opposite_ direction from each of refinery, no blocked path will be there. And if there's a block found that contains more resources of the alternative kind, it still does not affect the previous calculations. Also, if a single block of the alternative refinery outweighs, it still does not need to be recalculated because that was already done in the respective refinery based matrices.

|   i\j| 0  |1   |2   |3   |
|---|---|---|---|---|
|   0|0   |0   |0   |0   |
|   1|0 |0   |0   |0   |
|  2 |   0|  0 |0   |0   |

## Time Complexity

2D Array -> mutation : O(1)

2D Array -> look up : O(1)

Overall Complexity : O(3 x row x column) = O(row x column)

## Solution in Java (Iterative)

* `Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));` will throw `TLE` or `MLE`. It has been tested.

```java
import java.io.DataInputStream;
import java.io.IOException;

/* 
The `Reader` class aids only in taking inputs. Use any alternative that statisfies the time and memory constraints.
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
        int[][] radiumMatrix; // We will use this to memoize from East to West.
        int[][] uraniumMatrix; // We will use this to memoize from South to North.
        int[][] memoizationMatrix; // We will use this to track the best cummulative sum from either radium or uranium.

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

                    // East to West cummulative sum memoization
                    uraniumMatrix[i][j] += uraniumMatrix[i][j-1];
                }
            }

            // Input for Radium
            for(int i = 1; i <= m; i++){
                for(int j = 1; j <= n; j++){
                    radiumMatrix[i][j] = in.nextInt();

                    // South to North cummulative sum memoization
                    radiumMatrix[i][j] += radiumMatrix[i-1][j];
                }
            }
            
            // Memoization Matrix
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
