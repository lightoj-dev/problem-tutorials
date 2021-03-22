# LOJ-1212: Double Ended Queue tutorial
---
**What the problem wants**:You will be given 'n' queries & 'm' as the maximum size of a double ended queue. Depending on the queries you will have to print what kind of actions you performed on the double ended queue based on the queries and the value on which you performed the query.

---
**General approach to Solution :** It's a straight forward implementation problem. The problem can be solved using a built in double ended queue (you can also implement one from scratch), then inserting and removing elements from it . However, before performing any operation we will have to validate whether that operation (according to query) is valid or not.
Example : if the query is "popLeft" or "popRight" and the double ended queue is empty than we can't perform these operations and have to print "The queue is empty"
Same way if the query is "pushLeft" or "pushRight" while the double ended queue is full (it's size equals to 'm') you can't perform those operations and have to print "The queue is full".

If you don't know about a double ended queue data stracture check these links:
1. [Double ended queue on Wikipedia](https://en.wikipedia.org/wiki/Double-ended_queue)
2. [Youtube video explaining double ended queue](https://www.youtube.com/watch?v=j3rvizohd0I)
---
### Solution Code

Here's an accepted code for the problem implemented in C++.
Note: <deque> is C++'s built in implementation for double ended queues. Your specific programming language may have a different implementation for double ended queues.   
If you don't know about "deque" in C++ you can check out these blogs:
1. [Geek for Geeks blog on deque](https://www.geeksforgeeks.org/deque-cpp-stl/)
2. [More in depth about deque by cplusplus.com](https://www.cplusplus.com/reference/deque/deque/)
---
**Code :**

```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;  //number of test cases
    cin>>T;
    for(int case_number = 1 ; case_number <= T ; case_number++ )
    {
        cout<<"Case "<<case_number<<":\n";

        int n,m,x;
        string query;
        deque<int>d; //our double ended query.

        cin>>n>>m;

        for(int i=0; i<m; i++)
        {
            cin>>query;

            if( ( query == "pushLeft" || query == "pushRight" ) && ( d.size()>=n ) ) //checking if the double ended queue is full.
            {
                cin>>x;
                cout<<"The queue is full\n";
            }
            else if( (query == "popLeft" || query == "popRight" ) && d.size() == 0 ) //checking if the double ended queue is empty.
            {
                cout<<"The queue is empty\n";
            }
            else if( query == "pushLeft" )
            {
                cin>>x;
                d.push_front(x);
                cout<<"Pushed in left: "<<x<<'\n';
            }
            else if( query == "pushRight" )
            {
                cin>>x;
                d.push_back(x);
                cout<<"Pushed in right: "<<x<<'\n';
            }
            else if( query == "popLeft" )
            {
                x=d.front();
                d.pop_front();
                cout<<"Popped from left: "<<x<<'\n';
            }
            else if( query == "popRight" )
            {
                x = d.back();
                d.pop_back();
                cout<<"Popped from right: "<<x<<'\n';
            }
        }
    }
    return 0;
}
```     
