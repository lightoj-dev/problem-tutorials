## LOJ - 1114: Easily Readable
--- 

**What the problem wants :**
The problem at first gives a list of word. And after that some sentences ie a collection of word(s). We need to check in how many ways can the sentence be constructed from the words. But here the letter of a word can be rearranged except the first and last letter.  

**Problem Solution :**
So, as we can rearrange the letters of a word, that is the first thing that we will do. We will sort the letters of the word and count the frequency of this modified word. We can use a map or hash map to store the frequency against the words.
Some example of sorted word will make this clearer.
```
baggers => baeggrs
beggars => baeggrs
in => in
the => the
blowed => belowd
bowled => belowd
barn => barn
bran => barn
```
So, we have
```
freq[baeggrs] = 2
freq[in] = 1
freq[the] = 1
freq[belowd] = 2
freq[barn] = 2
```
we can see how this works now. We will do the same for the words of the sentence too. Then we will use the frequency of the words in the dictionary to find the count of different ways we can form the given sentence from the dictionaries. The required output is the product of frequency of the words of the sentence.  
**Be careful for integer overflow**

### Solution Code in C++ :
```cpp
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define ll long long


vector<string> splitSententence(string sentence){
    string word;
    vector<string> words;
    for(auto c: sentence){
        if( c != ' ' ) word += c;
        else{
            if( word.size() )
                words.push_back(word);
            word = "";
        }
    }
    if( word.size() )
        words.push_back(word);
    return words;
}
void solve(){
    int n;
    cin>>n;
    map<string,int> freq;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        // sort all characters except the first and last one
        // and incrementing its count
        if( s.size()>2 )
            sort(s.begin()+1,s.end()-1);
        freq[s]++;
    }
    int m;
    cin>>m; cin.ignore();
    while(m--){
        string sentence;
        getline(cin,sentence);
        // split the sentence into words
        vector<string> words = splitSententence(sentence);

        ll cnt = 1;
        for(auto word:words){
            // sort all characters except the first and last one
            // and incrementing its count
            if( word.size()>2 )
                sort(word.begin()+1,word.end()-1);
            cnt = cnt*freq[word];

        }
        cout<<cnt<<endl;
    }
}

int main(){
    FASTIO;
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        cout<<"Case "<<t<<":"<<endl;
        solve();
    }
}


```