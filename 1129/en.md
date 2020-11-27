# LOJ 1129 - Consistency Checker

In this problem, you will be given `T` testcases. The first line of each test case contains an integer `n`. Following `n` lines will contain a number of length `1-10` each. You are asked to check the consistency of the dataset. The consistency is, no number is a prefix of another number.

To recap, a substring of a string from its `0th` index is a prefix of that string. Like `123` is a prefix of `12345`, but `124`, `234`, or `132` is not.

This is a great problem to start **Trie Data Structure** if you haven't already.
**Tries** are an extremely special and useful data-structure that are based on the prefix of a string. They are used to represent the **“Retrieval”** of data.

Here are some resources to trie data structure you can understand and learn:-

- [Shafaetsplanet](http://www.shafaetsplanet.com/?p=1679)
- [HackerRank](https://m.youtube.com/watch?v=zIjfhVPRZCg&list=PLI1t_8YX-Apv-UiRlnZwqqrRT8D1RhriX&index=9&t=1s)
- [Tushar Roy - Coding Made Easy](https://m.youtube.com/watch?v=AXjmTQ8LEoI)

### Approach:

Atfirst, we create a trie for each new testcase. A single node of trie data structure will contain a `boolean` variable and an `array` of trie nodes of length `10`. The boolean variable will say if a string end on that node or not. The `10` size array will be enough for the next adjacent digit of the number because different digits can be atmost ten `(0-9)`.

The best way to take input of the `n` numbers for each testcase is as strings. Because trie deals with the prefix of a string. If we want to take `n` numbers as integers, we can. Because `integer` data type can hold between `-2147483648` to `+2147483647` which will be enough to hold an integer of length `1-10`. But still that won't be a smart approach.

So we simply take the `n` input numbers as strings and insert into the trie. Once the trie is formed, we create a function `isPrefix()` which will check if there is a single number prefix of another number or not in the trie. How will the function check? The function will traverse the trie, and if there is a single node which has the boolean variable value `true` but more trie nodes emit from that node, this confirms that it is a prefix.

Example, if our trie consists of two numbers `123` and `12345`, at the node for digit `3`, there is a number ending but still more node coming out from it. So, this confirms that the dataset is not consistent.

Visualization-
```
//A trie with two strings inserted, "123" and "12345"

        1(false)
         \
          2(false)
           \
            3(true) <-- ending of string "123" but not the leaf node!
             \
              4(false)
               \
                5(true) <-- ending of string "12345" and it is a leaf node
```

Lastly, after the answer is got, we delete the trie from the memory to avoid memory wastage in our program.

Try yourself before watching the code below.

### Code: (C++ solution)

```cpp
#include<iostream>
#include<stdio.h>
using namespace std;

///Trie/Radix Tree

struct trie
{
    bool endmark; //boolean variable to mark end of number
    trie *arr[10]; //10length array of trie nodes for 0-9
    //constructor
    trie()
    {
        endmark = 0;
        for(int i=0; i<=9; i++)
        {
            arr[i] = NULL;
        }
    }
} * root; //globally declaring variable of the struct

void insert(char s[])
{
    int n = 0;
    for( ; s[n]; n++) {} //size()

    trie *curr = root;
    for(int i=0; i<n; i++)
    {
        int x = int(s[i]-'0');
        if(curr->arr[x]==NULL) curr->arr[x] = new trie();
        curr = curr->arr[x];
    }
    curr->endmark = 1;
}

void del(trie* node)
{
    for(int i=0; i<10; i++)
    {
        if(node->arr[i]!=NULL) //recursive del!
            del(node->arr[i]);
    }
    delete(node);
}

bool isPrefix(trie *node)
{
    for(int i=0; i<=9; i++)
    {
        if(node->arr[i]!=NULL)
        {
            if(node->endmark) return 1;
            if(isPrefix(node->arr[i])) return 1;
        }
    }
    return 0;
}

int main()
{
    int t=0,tc=0;
    scanf(" %d", &tc);
    for(t=1; t<=tc; t++) //testcase
    {
        int i=0, j=0;
        root = new trie(); //creating the trie for this testcase

        int n; //no. of numbers
        scanf(" %d", &n);
        char s[10];
        while(n--)
        {
            scanf(" %s",&s[0]); //taking number as string
            insert(s); //inserting string into the trie
        }
        
        // The function determining the YES or NO as answer!
        isPrefix(root)? printf("Case %d: NO\n",t) : printf("Case %d: YES\n",t);

        del(root); //destroying the trie each time after a testcase ends to not hold memory anymore
    }
    return 0;
}
```
