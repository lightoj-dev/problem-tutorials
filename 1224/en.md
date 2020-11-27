# LOJ 1224 - DNA Prefix

In this problem, you will be given `T` testcases. The first line of each test case contains an integer `n`. Following `n` lines will contain DNA sample string of length `1-50` each. You are asked to calculate the maximum value of `(length of common prefix * number of DNA samples shared)`.

A simple visualization:
```
If two DNA samples are 'ACGTACGT' and 'ACG', here answer will be 08.
Because, length of 'ACGTACGT' is 08. Value = 8*1 = 8.
Both 'ACGTACGT' and 'ACG' has common prefix 'ACG' whose length is 03, then value = 3*2 = 6.
Maximum of 8 and 6 is 8.
```

This is a nice and easy problem on **Trie Data Structure**.

If you haven't learnt trie data structure, here are some resources to trie data structure you can understand and learn:-

- [Shafaetsplanet](http://www.shafaetsplanet.com/?p=1679)
- [HackerRank](https://m.youtube.com/watch?v=zIjfhVPRZCg&list=PLI1t_8YX-Apv-UiRlnZwqqrRT8D1RhriX&index=9&t=1s)
- [Tushar Roy - Coding Made Easy](https://m.youtube.com/watch?v=AXjmTQ8LEoI)

### Approach:

Atfirst, we create a trie for each new testcase. A single node of trie data structure will contain an `integer` variable and an `array` of trie nodes of length `4`. Since DNA string contains letters between {A,C,G,T}, a four sized array is perfect. Ofcourse, we won't want unnecessary occupying of extra memory in our program to avoid `MLE`(Memory Limit Exceeded).

You may have noticed trie usually contains a `boolean` variable, but I am taking an `integer` instead. This is a slight change you need to make for this problem on purpose. Because if you look carefully on the problem statement, we don't need the `boolean` endmark on where a DNA string ends. We just need the prefix. I used the `integer` variable to count the times of each node being visited while inserting the DNA strings into the trie. This count variable is dynamically keeping track of a single node being used in how many DNA strings.

Visualization-
```
//A trie with two DNA strings inserted, "ACGACG" and "ACGTACG"

            A(count=2)
             \
              C(count=2)
               \
                G(count=2) //value = 3*2 = 6; because 03 length prefix is shared by 2 DNA strings
               / \
     (count=1)A   T(count=1)
             /     \
   (count=1)C       A(count=1)
           /         \
 (count=1)G           C(count=1)
                       \
                        G(count=1) //value = 7*1=7; 7 length prefix is shared by 1 DNA strings
```

Lastly, after the answer is got, we delete the trie from the memory to avoid memory wastage in our program.

Try to code yourself before watching the code below.

### Code: (C++ solution)

```cpp
#include<iostream>
#include<stdio.h>
using namespace std;

///Trie

struct trie
{
    //bool endmark; //we dont need endmark of string for this problem! :)
    int count;
    trie *arr[4]; //04 length array of trie nodes for {A,C,G,T}
    //constructor
    trie()
    {
        count = 0; //to count prefix occurences
        //endmark = 0;
        for(int i=0; i<=3; i++)
        {
            arr[i] = NULL;
        }
    }
} * root; //globally declaring variable of the struct

void insert(char s[])
{
    int n = 0;
    for( ; s[n]; n++) {} //n is size of the string

    trie *curr = root;
    for(int i=0; i<n; i++)
    {
        int x = 0; //default for 'A'
        if(s[i]=='C') x=1;
        else if(s[i]=='G') x=2;
        else if(s[i]=='T') x=3;
        if(curr->arr[x]==NULL) curr->arr[x] = new trie();
        
        curr = curr->arr[x];
        curr->count++;
    }
}

void del(trie* node)
{
    for(int i=0; i<4; i++)
    {
        if(node->arr[i]!=NULL) //recursively deleting!
            del(node->arr[i]);
    }
    delete(node);
}

int compute(trie *node, int level)
{
    int ret = 0;
    ret = (node->count * level);
    
    for(int i=0; i<4; i++)
    {
        if(node->arr[i]!=NULL)
        {
            ret = max(ret , compute(node->arr[i], level+1));
        }
    }
    return ret;
}

int main(void)
{
    int t=0,tc=0;
    scanf(" %d", &tc);
    for(t=1; t<=tc; t++) //testcase
    {
        int i=0, j=0;
        root = new trie(); //creating the trie for this testcase

        int n; //no. of DNA strings
        scanf(" %d", &n);
        char s[50];
        while(n--)
        {
            scanf(" %s",&s[0]); //taking DNA string
            insert(s); //inserting string into the trie
        }
        
        // The function determining the maximum answer!!
        printf("Case %d: %d\n", t, compute(root, 0));
        
        del(root); //destroying the trie each time after a testcase ends to not hold memory anymore
    }
    return 0;
}
```
