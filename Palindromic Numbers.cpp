#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e17
#define all(vec) vec.begin(),vec.end()
#define ld long double
#define ull unsigned long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool isPrime(ll n){if(n<=1)return 0;if(n<=3)return 1;if(n%2==0||n%3==0)return 0;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return 0;return 1;}
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
vector<ll> _in(ll n){vector<ll> vec(n);f(i,0,n)cin>>vec[i];return vec;}
ll _power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll _power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1;a *= a; a %= mod;} return p % mod;}
const long long int mod = 1000000007;
ll solve();
int main(){
    IOS
    long long t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        ll ans = solve();
        cout << "Case " << i << ": " << ans << "\n";
    }
    return 0;
}
// ANSWER IS FROM HERE //
ll _stoi(string s){
    reverse(all(s));
    ll fac = 1;
    ll ans=0;
    for(auto i: s){
        ans += fac*(i-48);
        fac*=10;
    }
    return ans;
}
ll all_of_n(ll x){
    if(x == 0) return 0;
    if(x == 1) return 10;
    if(x == 2) return 9;
    ld n = x;
    n = (n-2)/2;
    n = ceil(n);
    ll p = n;
    ll ans = 9 * _power(10,p);
    return ans;
}
ll initial(ll n){
     string s = to_string(n);
     ll y = s.length();
     if(y == 1) {return n+1;}
     ll x = y;
     if(x%2) x /= 2;
     else x = (x/2) - 1;
     ll ans = 0;
     ll fac = 1;
     for(int i=x;i>=0;i--){
         if(i!=0){
             ans += fac*(s[i]-48);  
         }
         else{
             ans += fac*(s[i]-49);
         }
         fac *= 10;
     }
     for(int i=0;i<s.length()/2;i++){
         s[y-i-1] = s[i];
     }
     ll temp = _stoi(s);
     if(temp <= n) ans++;
     return ans;
}
ll _final(ll n){
    ll sz = to_string(n).length();
    ll total = all_of_n(sz);
    ll x = initial(n-1);
    ll ans = total - x;
    return ans;
    // ll sz = to_string(n).length();
    // ll total = all_of_n(sz);
    // if(n != _power(10,sz-1)) total -= initial(n-1);
    // return total;
}
ll solve(){
  // Credits : MOHIT BABANI
  // Solution link : https://lightoj.com/submission/2048224
    ll a,b;cin>>a>>b;
    ll MIN = min(a,b);
    ll MAX = max(a,b);
    a = MIN;b = MAX;
    ll ans = 0;
    ll sz1 = to_string(a).length();
    ll sz2 = to_string(b).length();
    for(int i=sz1;i<=sz2;i++){
        ans += all_of_n(i);
    }
    ll temp = 0;
    if(a != _power(10,sz1-1) && a != 0) temp += initial(a-1);
    if(a == 1) temp += 1;
    if(b != _power(10,sz2)-1) temp += _final(b+1);
    ans -= temp;    
    return ans;
}
