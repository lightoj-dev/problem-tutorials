# LOJ 1011 - Marriage Ceremonies

In this problem, you will be given `T` testcases. The first line of each test case contains  integer `N` which is the number of both man and woman. Now each of the N lines line consist of N integers denoting the priority of the jth woman toward ith man.Let's analyze this with a testcase

3
1 2 3
6 5 4
8 1 2

Here the 1 in the first row and first column denotes the priority of the 1st man towards 1st woman and 2,3 of first row denotes the priority of the 1st man towards 2nd and 3rd woman respectively
So from the first row we can notice that first man likes the 3rd woman most among the 3 womans. So what we have to find is we will assure the marriage of N woman with N man with no overlappings but the summation of choosings of all the marriage has to be maximum
The output of this testcase is 16.Now the question comes why it is 16? Well it's because the 3rd man from the 3rd row married 1st woman which is the highest priority of the third row
The 2nd man married the 2nd woman who's priority is 5 but it is not the maximum priority of the row.Now ask yourself why 2nd man married the 2nd woman despite having a greater priority towards 1st woman
The answer is unfortunately the 3rd man married the 1st woman who's priority surpasses the priority of the 2nd man and 1st woman isn't avaibable since he is already married with the 3rd man and that's why 2nd man has to look for his 2nd priority which is the 2nd woman.
And then he got married with the 2nd woman.So upto now 3rd man married 1st woman,2nd man married 2nd woman and now the only man and woman left are 1st and 3rd respectively and they got engaged.
Now that sum of the priority is 3+5+8=16.And this combination is the maximum of all the combinations without having any overlappings and that's why this is the answer.

### Approach:
In order to solve this problem, there are a few prerequisites that need to be fulfilled which are: you need to have a basic understanding of dynamic programming and bit manipulations. The tutorials you can look and follow to develop your knowledge regarding these topics is provided in the "Resources" section

To solve this problem we will make a "Bitmask funtion" where the parameters that need to be taken are the `ith` man and current mask which is under effect currently.
In order to invoke this function we will send (0.0) and start computing the answer of this problem.Now for the `ith` man we will try to look for `1<<j` woman where `1<<j` can be 1,2,4
Here 1,2,4 denotes first,second,third woman respectively.Now if 1st man marries the 1st woman we will make the mask `(mask|(1<<0))==1)`.It  means the woman number 1 is married with 1st man but if we made `(mask|(1<<1)==2)` it means the first man married the 2nd woman.This way we will have to consider all the jth woman to find the greatest maximum sum of pririties for the `ith` man
Now suppose the 2nd man marries 2nd woman then we make the `mask|(1<<1)==1|2==3`.Now if you know the "Bit Manipulation Technique" you will know `(1<<1)==2^1=2` and you know 2 means taking 2nd woman into consideration and masking 2 with the previous 1 makes it 3 means both 1st and 2nd woman are married and they can't marry any other man neither any man can consider marrying them either
Now since 1st woman and 2nd woman are taken the mask is 3==011 . Now for 3rd woman we can't take the either "1s" of the binary number.So the only option left for 3rd man is the 3rd woman which is the 3rd bit from the right which is still zero
Now choosing the 3rd bit that is the 3rd woman we make `mask|(1<<2)==3|4==7` that is, we considered all the man and woman without any overlapping and so we completed a combination and so we return 0.And how we ignored the overlapping?For the ith man we simply avoided woman or bit which is set as `1` and we condered the bits which are `0` and considered all combinations we can take and stored the maximum inside a variable
That maximum number which is a combination is the answer.The number of total combinations is `2^N-1` and we will have to compute all of them and return the maximum one out there which will denote the maximum sum of priority.

The recursive formula of this problem is:
`
 bitmask(i,(1<<n)-1)=0 
 bitmask(i,mask)=max(a[i][j]+bitmask(i+1,mask|(1<<j)) where i<=n,j<=n and a[i][j] consists of priority of ith man for jth woman
`

### Resources:
Here are some resources of  **Bit Manipulation,Basic Dp and BitMask Dp** so that you can have a deeper understanding and learn to solve problems using these resources:-

- [Shafaetsplanet](https://www.shafaetsplanet.com/?p=1357) **(BitMask Dp)**
- [HackerEarth](https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/tutorial/) **(Basics of Bit Manipulation)**
- [Bangladesh Advanced Computing Society - BACS](https://www.youtube.com/watch?v=cbgdSX2pXcQ)   **(BitMask Dp)**
- [GeeksforGeeks](https://www.geeksforgeeks.org/dynamic-programming/)   **(Basic and Advanced Types of DP)**


### C++ Implementation:
```
#include<bits/stdc++.h>
using namespace std;
int a[16][16];
int dp[1<<16];//1<<16==2^16 since in worst case there can be 16 marriage ceremonies
int n;
int bitmask(int i,int mask)
{
    if(mask==(1<<n)-1) //base case
        return 0;
    int &ans=dp[mask];//& is a reference operator and any change brought to a reference variable will be set to the dp array at mask index because of this operator
    if(ans!=-1)
        return dp[mask];//since we have already computed that value in previous iterations
    for(int j=0; j<n; j++)
    {
        if((mask&(1<<j))==0)
        {
            ans=max(ans,a[i][j]+bitmask(i+1,mask|(1<<j)));
        }
    }
    return ans;
}
main()
{
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
            }
        }
        memset(dp,-1,sizeof dp);
        cout<<"Case "<<k<<": "<<bitmask(0,0)<<endl;
    }
}
```
