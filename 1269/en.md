## LOJ-1269: Consecutive Sum

**Problem Insight**

<div style="text-align: justify">
Little Jimmy is actually performing the [<b>xor</b>](https://en.wikipedia.org/wiki/Exclusive_or) operation. So, we are required to find the maximum xor subarray, and the minimum xor subarray.
And Notice that xor of the numbers range from only `0` to `255`.
</div>

<br>

**Solution**

<div style="text-align: justify">
Given an array of length <b>`n`</b>. We call <b>`cxor[i]`</b> the xor of all the array elements in range <b>`[0, i]`</b>, with <b>`i`</b> inclusive. Then the xor of all the elements in range <b>`[i, j]`</b>,
with <b>`j`</b> inclusive, is simply <b>`cxor[i-1]^cxor[j]`</b>. And so, we will precalculate all the <b>`cxor[i]`</b>s for <b>`0 < i < n`</b> in the same way as calculating
the cumulative summations. And then we will calculate xors for all subarray <b>`[i, j]`</b> with <b>`0 <= i < j < n`</b>. The maximum xor is the answer.
</div>

<br>
  
<div style="text-align: justify">
The problem is <b>`n`</b> can be as big as <b>50000</b>. So the total number of subarrays can be a maximum of <b>50000*49999/2</b> which is well over <b>10<sup>9</sup></b>. So this approach will not work.
But, as we all know, the xor of two numbers is maximum when their binary representations are as different as possible, meaning, if <b>`cxor[j]`</b> has a <b>`1`</b> in the 
<b>`kth`</b> position, it's better if <b>`cxor[i-1]`</b> has a <b>`0`</b> in that position in order to get the xor maximized. So, for each <b>`j`</b> we only need to find an
<b>`i`</b> such that the binaries of <b>`cxor[i-1]`</b> and <b>`cxor[j]`</b> have as many mismatches as possible.
</div>
  
<br>
But, how do we find such <b>`cxor[i-1]`</b> efficiently. One way is to use [<b>Trie</b>](https://www.geeksforgeeks.org/trie-insert-and-search/) data structure.
We keep inserting each of <b>`cxor[i]`</b> in a loop. And in each cycle of the loop, we first search for the most mismatched cumulative xor saved in the tree and perform
the xor operation all the while checking if the xor is maximum. And then insert the current <b>`cxor[i]`</b>.
</div>

**Tip:** Be careful about the memory while using Trie. It is good practice to clear the memory every testcase. And also, avoid using `string` in cpp,
and use `char` array.

<br>
<br>


**Recommended for Learner**
<br>
  1. <b>Binary Conversion:</b> https://www.geeksforgeeks.org/program-decimal-binary-conversion/
  2. <b>Trie Tree Data Structure:</b> https://www.geeksforgeeks.org/trie-insert-and-search/
<br>

## Code(C++)
```
#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode * bit[2];
    TrieNode(){
        this->bit[0] = this->bit[1] = NULL;
    }

    void insert(char s[], int i){
        if(i == 32) return;
        if(bit[s[i]-'0'] == NULL){
            bit[s[i]-'0'] = new TrieNode();
        }
        bit[s[i]-'0']->insert(s, i+1);
    }

    void searchMax(char s[], int i, char c[]){
        if(i == 32) return;
        int next = s[i]-'0';
        if(bit[1-next] == NULL){
            c[i] = '0';
            bit[next]->searchMax(s, i+1, c);
        }
        else {
            c[i] = '1';
            bit[1-next]->searchMax(s, i+1, c);
        }
    }

    void searchMin(char s[], int i, char c[]){
        if(i == 32) return;
        int next = s[i]-'0';
        if(bit[next] == NULL){
            c[i] = '1';
            bit[1-next]->searchMin(s, i+1, c);
        }
        else{
            c[i] = '0';
            bit[next]->searchMin(s, i+1, c);
        } 
    }

    void exterminate(){
        if(bit[0]) bit[0]->exterminate();
        if(bit[1]) bit[1]->exterminate();
        delete this;
    }
};

void to_binary(int n, char c[]){
    for(int i = 0; i < 32; i++){
        if(n&1) c[i] = '1';
        else c[i] = '0';
        n >>= 1;
    }
    reverse(c, c+32);
}

int to_decimal(char c[]){
    int x = 0;
    for(int i = 0; i < 32; i++){
        x = 2*x + (c[i]-'0');
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; scanf("%d", &T);

    int n, ar, mx, mn, cxor;
    char bin[32];
    char mns[32], mxs[32];

    for(int t = 1; t <= T; t++){
        int n; scanf("%d", &n);
        mx = cxor = 0;
        mn = INT_MAX;

        TrieNode * root = new TrieNode();
        for(int i = 0; i < 32; i++){
            bin[i] = '0';
        }
        to_binary(0, bin);
        root->insert(bin, 0);

        for(int i = 0; i < n; i++){
            for(int i = 0; i < 32; i++){
                bin[i] = '0';
                mxs[i] = '0';
                mns[i] = '0';
            }
            scanf("%d", &ar);

            cxor = cxor ^ ar;
            to_binary(cxor, bin);

            root->searchMax(bin, 0, mxs);
            mx = max(mx, to_decimal(mxs));

            root->searchMin(bin, 0, mns);
            mn = min(mn, to_decimal(mns));

            root->insert(bin, 0);
        }
        printf("Case %d: %d %d\n", t, mx, mn);
        root->exterminate();
    }
    return 0;
}
```
