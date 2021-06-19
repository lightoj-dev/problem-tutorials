# LOJ 1187- Lining up Students

### Problem Summary
You will be given T test cases to solve. In each test case you will be given a number N which defines the number of students, then there will be a line containing N integers which indicate the number of students taller than the ith student in the left. You will need to find which student is in front of the line.

### Solution

Short:
The idea is quite simple, suppose we have LIS(A vector/array, containing numbers from 1 to N),we start traversal from the Nth position and  we will always need to place (i-A[i])th student from the LIS in the `i`th place and remove him from the list.

Now why to always get the `(i-A[i])`th student? Because only then there will be `A[i]` students taller than the `i`th student in the left. For example: Suppose we have a line: 1,2,3,4,5,6. We want the student in the `6th` position to have 2 students who are taller in left, then we can shift 4 to end. Then the new line  will look like : 1,2,3,5,6,4

Brief:
A[] = Given array.
N = Given number of students.
LIS[] = List of students, containing numbers from 1 to N.

We will start traversing from the `Nth` position, while maintaining a list of students(LIS) who we didn't put in a position yet. For each place subtract the value which indicates the number of students towards it's left, if our current position is `i`, then:
          
        let `P` = i - A[i]`;

Now, we will place the the student who is in position `P` in our LIS in the `i'th` position. Then remove that student from our LIS. We will continue this process until we reach the first position.


Let's solve for a case to demonstate how we will proceed.
3  <-N
0 1 2   <- Array containing the number of students taller than the i'th student

LIS={1,2,3};

Since we need to find which student is at front i.e position 1, let's start traversing from the end i.e Nth position. We will need to do N-1 steps.

Step-1: Current LIS status: LIS={1,2,3};

            Current position is 3, the value in the 3rd position of the given array is 2.,
            Now pos = 3 - 2 = 1, in the 1st position of our LIS we have 1, so we will place 
            1 in the 3rd position and remove him from the list.

Step-2: Current LIS status: LIS={2,3};

            Current position is 2, the value in the 2rd position of the given array is 1.,
            Now pos = 2 -1 = 1, in the 1st position of our LIS we have 2, so we will place 
            2 in the 2nd position and remove him from the list.

print the only remaining student as he will be in front of the list, in this case 3, which is our ans.

### Coding Approach:
  A brute force solution with the above idea using vector/array can result into TLE, as we will always need to erase 
 an element and shift the rest. But we can easily solve this using PBDS(Policy Based Data Structure).
  PBDS: https://codeforces.com/blog/entry/11080

### Code

    #include<bits/stdc++.h>
    #include<ext/pb_ds/assoc_container.hpp>
    #include<ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    using namespace std;
    template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    typedef long long int ll;
    const int MAX = 1e5+500;
    int arr[MAX];
    int main()
    {
        int t;
        scanf("%d",&t);
        for(int cs=1;cs<=t;cs++){
            int n;
            scanf("%d",&n);
            ordered_set<int>os;//PBDS
            for(int i=1;i<=n;i++)
            {
                scanf("%d",&arr[i]);
                os.insert(i);
            }
            for(int i=n;i>1;i--){
                int p=i-arr[i]; ///Getting the Pth position
                auto it=os.find_by_order(p-1); ///Using it=os.find_by_order we can get the element at that position
                os.erase(os.find(*it)); ///Deleting/erasing it from our list.
            }
            printf("Case %d: %d\n",cs,*os.begin());
        }
        return 0;
    }






