### 1266 - Points in Rectangle

**Prolblem Description:** This problem is about finding the number of points in a rectangle whose sides are parallel to axis. All the points and rectangles consist of 2D Cartesian co-ordinates. A point that lies in the boundary of a rectangle is considered inside.

**Observation:** The Idea was quite simple that after seeing a large number of query over a grid that somehow we have to do a little bit storing of precalculated result of the previous points.
Here We are using a well known <em>technique Bit Index Tree or Fenwick Tree over 2-d Grid</em> If you do not know the algo visit the it and its varaints here
<a here="https://cp-algorithms.com/data_structures/fenwick.html" target="_blank">
Fenwick Tree
</a>   


**Solution:**
### C++ code
```cpp

#include<bits/stdc++.h>
using namespace std;
using  ll = long long int;



// These are usual operation on the Fenwick Tree Refer 
// Above mentioned Link

// For adding a point and updating all the of the 
// Ranges which have this point int their range
void add(vector<vector<ll>>&ft, ll x, ll y) {
    ll j = y;
    while(x<=1000) {
        j =y; 
        while(j<=1000) {
            ft[x][j] += 1;
             j = j |(j+1); 
    } 
    x = x | (x+1);
    }

}


// Finding total points inside the origin and (x,y) ractangle
ll summ (vector<vector<ll>>&ft , ll x, ll y) {
    ll val =0;
    ll j=y;
    while(x >=0) {
        j =y;
         while(j>=0) {
            val += ft[x][j];
            j = (j & (j+1))-1;
            }
        x = (x & (x+1))-1;
    }
    return val;
}







 void solve() {
     ll q;
     cin>>q;
    
    // Frist we have initialized a Grid of 1000X1000
    // This is basically our Fenwick Grid
    // Here we stores the actual point inside the 
    // rectangle having its opposite corner at (0,0) 
    // and (x,y)
    // So ft[x][y] = the number of point mentioned above

    vector<vector<ll>>ft(1001,vector<ll>(1001,0));

    // For Unique Query Refer PS
    set<pair<ll,ll>>st;

    while(q--) {
            ll t;
            cin>>t;
            if(t==0) {
                ll x,y;
                cin>>x>>y;
              ll is = st.size();
              st.insert({x,y});
              // If Query is unique we will process
              // We will add the point to the fenwick 
              // tree and update it

              if(is<(ll)st.size()) {
                    add(ft,x,y);
            }    

        }
        else {

              ll x1, y1,  x2 ,  y2;
               cin>>x1>>y1>>x2>>y2;

            // To calculate the point inside the 
            //   Rect (x1,y1) and Rect(x2,y2)
            // We do not directly have the count of Points
            //   So we somehow first calcualte the point from origin to (x,y) then 
            // Remove the extra point 

             ll lp = summ(ft,x2,y2);
            ll fc = summ(ft,x1-1,y2);
            ll sc = summ(ft,x2,y1-1);
            ll ap = summ(ft,x1-1,y1-1);
            ll ans = lp+ap-fc-sc;
            cout<<ans<<endl;
            }
    }
}





int main() {
    // Ignore just for the fast input output since 
    // There are very large queries

    ios_base::sync_with_stdio(false);
    cin.tie(0);

   // For Different Test Cases
    int t;
    cin>>t;

    for (int i=1;i<=t;i++) {
        cout<<"Case "<<i<<":"<<endl;
         solve();
    }
}

```

### Time Complexity: for Each and update (log(n)^2)

### Hence complete complexity: (log(n)^2) q T
