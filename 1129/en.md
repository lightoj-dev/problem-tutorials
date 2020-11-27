# 1129 - Consistency Checker

**Problem Link:** [click here](http://lightoj.com/volume_showproblem.php?problem=1129)

**Algorithm:** [Trie Tree Data Structure on Shafaetsplanet](http://www.shafaetsplanet.com/?p=1679) **Shafaetsplanet** blog has really awesome tutorial on trie data structure. Also you can learn from anywhere.
***Some youtube resources on trie:-***
- [Tushar Roy - Coding Made Simple](https://m.youtube.com/watch?v=AXjmTQ8LEoI)
- [HackerRank](https://m.youtube.com/watch?v=zIjfhVPRZCg)

### Theory:
If you have learnt **trie data structure** well, this problem is really easy for you.

You will be given some numbers with length 1-10. And you have to find **"is atleast one number a prefix of another number or not"**. (To recap, a substring from the 0th index of a string is a prefix of that string. Ex- **123** is a prefix of **12345**, but **124**, **132** or **234** is not a prefix of **12345**.) So simply take the numbers as strings and insert the strings into the trie tree.

**How will be the trie node?!** Since a number can have digit only between 0-9, then the trie node will have one boolean variable and an array of trie nodes of length 10. Once you complete inserting the numbers as strings into the trie, you will write a function which will check if a single string is a prefix of another or not, and the function will return true or false. Based on that, you got your answer. :)

### Code: (C++ solution)
This is an accepted solution of mine!
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
        if(i+1==n) {
            curr->arr[x]->endmark = 1;
            break;
        }
        curr = curr->arr[x];
    }
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
