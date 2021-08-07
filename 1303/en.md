## Loj-1303: Ferris Wheel 

**What the problem wants :** The given problem gives us two numbers `n`(number of people in the line at beginning) and `m` (number of seats in the ferris wheel) . We have to figure out the 'total time' it takes for all the people to ride each seat of the ferris wheel once.

We have three rules for this operation.

1 . They will form a queue from 1 (front) to n (back) and they want to sit alone in a seat. 
2 . When a person gets out from one seat (he just rode in that seat), then if he has ridden in all the seats, he will leave, otherwise he will join in the back of the queue.
3 . only one person can ride a seat each time.(no sharing)
4 . The seats rotate in clockwise manner. After seat 1 comes 2 , then 3 ... then 1 again after the 'm' th seat. It takes 5 sec for the seats to change.


**Approach to solution :** The problem can be considered a simulation problem using any linear data structure . In order to solve the problem we simply have to simulate the entire process in code. 

We can represent the queue of people using a list & the seats of the ferris wheel as an array . At every step we will first decide the lowest seat or the seat which will be boarded. If the seat contains a person then we will check if he has visited all seats. If he has visited the seats simply remove him , otherwise push him back to the list. Then check for the first eligible person on the line to sit on that seat and remove him from the list. If no one in line is eligible continue the process. Update the number of lowest step afterwards and keep track of the number of times the seat changes or the ferris wheel rotates.

The entire process will continue till everyone has sat on each of the seats.

**Tip :** Because we have to simulate the process step by step , it's very helpful to modularize the code . This means breaking the code into smaller functions for each action or operation .

---
## Solution code in C++ :
```cpp
#include <bits/stdc++.h>
using namespace std;

//function to check if a person has visited all the seats in Ferris Wheel
bool fully_visited(int vis[30][30],int m,int person)
{
    for(int i=0; i<m; i++)
    {
        if(vis[person][i]==0)
            return false;
    }
    return true;
}

//Function for selecting The first eligible person in line to get on the ferris wheel

int select_person(list<int> line,int vis[30][30],int lowest_seat)
{
    for(list<int>::iterator it = line.begin(); it!=line.end(); it++)
    {
        if(vis[*it][lowest_seat]==0)
            return *it;
    }
    return 0;
}

//A function to check if the ferris wheel is occupied (if there is someone on any of the seats)

bool wheel_occupied(int wheel[],int m)
{
    for(int i=0; i<m; i++)
    {
        if(wheel[i]>0)
            return true;
    }
    return false;
}

int main()
{
    int t,cas=1;
    cin>>t;
    
    while(t--)
    {
        int n,m,ans=0,lowest_seat=0,done=0; // 'done' is for counting the number of people who have ridden in each seat on the ferris wheel.
        
        // 'vis' array keeps track of which seats have the people already sat at.
        int vis[30][30]= {};
        
        list<int> line; //represents the queue

        cin>>n>>m;

        for(int i=1; i<=n; i++)
        {
            line.push_back(i);
        }

        int wheel[m+2]= {}; //represents the ferris wheel 
        
        do
        {
            lowest_seat = (lowest_seat + 1) % m; // for updating the current lowest seat.

            if(wheel[lowest_seat]!=0)
            {
                if(fully_visited(vis,m,wheel[lowest_seat]))
                {
                    ++done;
                    wheel[lowest_seat] = 0;
                }
                else
                {
                    line.push_back(wheel[lowest_seat]);
                    wheel[lowest_seat] = 0;
                }
            }

            int new_person = 0;

            new_person = select_person(line,vis,lowest_seat);
            line.remove(new_person);
            wheel[lowest_seat] = new_person;
            
            if(new_person!=0)
            {
                vis[new_person][lowest_seat] = 1;
            }

            ++ans; // to track the number of times the wheel rotates.
        }
        while(wheel_occupied(wheel,m) || (done<n)); 

        cout<<"Case "<<cas++<<": "<<ans*5<<'\n'; // 'ans*5' because each rotation or change of position of seats takes 5 units of time.
    }

    return 0;
}

```
---