
<h1 align="center"> <b>LightOj 1428 (Melody Comparison) </b> </h1>
<hr/>

# **Tags**

**`string`** , **`suffix array`** , **`binary search`** , **`kmp`**

# **Idea**

First , think an easier version of this problem . How many _**distinct**_ _**substrings**_ are possible of a string S ?  

Let's solve an easier version of this easy problem . How many _**substrings**_ are possible of a string S ?  

For any `p[i]` i.e for any suffix , the number of possible substrings are `(S.size() - p[i])`    
Then the _**ending position**_ for possible substrings starts from `p[i]` and ends at `S.size() - 1` **(0 based indexing)** . Hence the number of possible substrings are `(S.size() - p[i])`  

Now , how many of them are _**distinct**_ ?  

We need to look into the **LCP array** for that . When we know `LCP(i)` , we know the length of **Longest Common Prefix** of suffix `i` and suffix `i-1`  
Now , the _**ending position**_ for possible substrings starts from `p[i] + LCP(i)` and ends at `S.size() - 1` **(0 based indexing)**  

Why  `p[i] + LCP(i)` ?  
> Because in the `i-1` th suffix we have already considered the substrings that start from `p[i]` , `p[i] + 1` , ... , `p[i] + LCP(i) - 1`   

Now that we have solved all the easier versions . Let's solve our problem :D

How many among the distinct substrings _**doesn't contain another string as a substring**_ ?  
Let's call this other string `SUB`  .
What's the thing that will change in our substring count ?  
> For any suffix , the ending position for possible substrings still starts from `p[i] + LCP(i)` . But this time we can't end at `S.size()-1` as that could lead to have substring having the string `SUB` . So , we need to find the new ending positions .  

For this part we need to know the positions where our string `SUB` appears in our string `S` . We can use _**KMP**_ for that . Also we can b_**inary search on suffix array**_ for that .
Anyway , now that you know where our string `SUB` occurs , you know that then ending position for that values will be `p[i] + SUB.size() - 1` . As , if we go one more we would have considered the string `SUB`.  
Now , we can solve for the rest of the positions easily .  

Let's see an example for this case.  

Let , S = `abacdaba`  & SUB = `aba`    

> **abacdaba**  
0^^^^5^^  

`aba` occurs in position 0 and 5 . What are the ending positions of 0 and 5 ?   
For , 0 it is 0+2 = 2 . We can not end anywhere starting from 2 and beyond . So , we can make `a` `ab` but not `aba`

So , the ending positions become ,
> **abacdaba**  
2^^^^7^^

For other positions ?
> **abacdaba**  
27777788

Why ?
Well , figure that out yourself :p It's really easy to see why

```cpp

/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;
const LL LINF = 1e17;

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

void count_sort(vector<int> &p,vector<int> &c)
{
    int n = p.size();

    vector<int>cnt(n);

    for(auto el:c)
        cnt[el]++;

    vector<int>np(n);
    vector<int>pos(n); /// pos[i] = first empty position in bucket i

    pos[0] = 0;
    for(int i=1; i<n; i++)
        pos[i] = pos[i-1] + cnt[i-1];

    for(auto el:p)
    {
        int i = c[el]; /// bucket
        np[pos[i]] = el; /// putting element in bucket
        pos[i]++; /// empty position in bucket i increased
    }

    p = np;

}

vector<int> buildSuffixArray(string s)
{
    s += "$";

    int n = s.size();

    /// init p , c

    vector<PII>v(n);

    for(int i=0; i<n; i++)
        v[i] = {s[i],i};
    sort(ALL(v));

    vector<int>p(n), c(n);
    for(int i=0; i<n; i++)
        p[i] = v[i].S;

    c[p[0]] = 0;
    for(int i=1; i<n; i++)
    {
        if(v[i].F!=v[i-1].F)
            c[p[i]] = c[p[i-1]] + 1;
        else
            c[p[i]] = c[p[i-1]];
    }

    /// logN times

    int k = 0;

    while((1<<k) < n)
    {
        for(int i=0; i<n; i++)
            p[i] = (p[i] - (1<<k) + n)%n;

        count_sort(p,c);

        vector<int>nc(n);

        nc[p[0]] = 0;
        for(int i=1; i<n; i++)
        {
            PII now  = { c[p[i]] , c[ (p[i]+(1<<k))%n] };
            PII prev = { c[p[i-1]] , c[ (p[i-1]+(1<<k))%n] };

            if(now!=prev)
                nc[p[i]] = nc[p[i-1]] + 1;
            else
                nc[p[i]] = nc[p[i-1]];
        }

        c = nc;
        k++;
    }

    /// after all the iterations , c[i] = position of the suffix i in p

    return p;
}

int lowerBound(int lo,int hi,string s,string key,vector<int> &ara)
{
    while(lo!=hi)
    {
        int mid = lo + (hi-lo)/2;

        string chk = s.substr(ara[mid],key.size());

        if(chk<key) lo = mid + 1;
        else hi = mid;
    }

    return lo;

}

int upperBound(int lo,int hi,string s,string key,vector<int> &ara)
{
    while(lo!=hi)
    {
        int mid = lo + (hi-lo)/2;

        string chk = s.substr(ara[mid],key.size());

        if(chk<=key) lo = mid + 1;
        else hi = mid;
    }

    return lo;
}

vector<int> buildLCPArray(string s,vector<int> &p)
{
    s+="$";
    int n = s.size();

    vector<int>rnk(n);

    for(int i=0;i<n;i++)
        rnk[p[i]] = i; /// this is basically the c array after all iterations

    vector<int>lcp(n);

    int k = 0;

    for(int i=0;i<n-1;i++)
    {
        int pi = rnk[i];
        int j = p[pi-1];

        /// lcp[i] = lcp(s[i...],s[j...])

        while(s[i+k]==s[j+k]) k++;
        lcp[pi] = k;
        k = max(k-1,0);
    }

    return lcp;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    for(int qq=1;qq<=tc;qq++)
    {
        string s,sub;
        cin>>s>>sub;

        int n = s.size();

        vector<int> p = buildSuffixArray(s);
        vector<int>lcp = buildLCPArray(s,p);

        vector<int> ending_pos(p.size(),-1);

        int lo = lowerBound(0,n+1,s,sub,p);
        int hi = upperBound(0,n+1,s,sub,p);

        for(int i=lo;i<hi;i++)
            ending_pos[p[i]] = p[i] + sub.size() - 1;

        int now = s.size();

        for(int i = (int)ending_pos.size() - 1;i>=0;i--)
        {
            if(ending_pos[i]==-1) ending_pos[i] = now;
            else now = ending_pos[i];
        }

//        for(int i=0; i<(int)p.size(); i++)
//        cout<<p[i]<<" "<<lcp[i]<<" "<<s.substr(p[i],s.size()-p[i])<<endl;
//        cout<<endl;

        LL ans = 0;

        for(int i=0;i<lcp.size();i++)
        {
            int st = p[i] + lcp[i];
            int en = ending_pos[p[i]];

            if(en>st) ans += en-st;
        }

        cout<<"Case "<<qq<<": ";
        cout<<ans<<endl;
    }

    return 0;
}

/**
100
abacdaba
aba
**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}

```