# LOJ 1370 - Bi-shoe and Phi-shoe

In this problem, you will be given `T` testcases. The first line of each test case contains a single integer `n` where `n` denotes the number of students of Phi-Shoe who is a massively popular coach.

The next line contains n space separated integers denoting the lucky numbers for the students through which assistant of Phi-Shoe,Bi-Shoe can help students in buying bamboos.Now, in the problems statement it was told to design an algorithm through which minimum amount of money will be spent for buying bamboos for the students.


### Approach:
In order to solve this problem, there is a prerequisite that need to be fulfilled which is: you need to have a basic understanding of Sieve of Eratosthenes.The tutorials are given below in the "Resources" section.

So having a clear concept of the topic mentioned above, we can solve this problem.

In the problem we are given, ```Score of a bamboo = Φ (bamboo's length)``` where score of the bamboos denote the lucky numbers we found in the second line of each testcase.By ```Φ(n)``` it was meant count of numbers less than n that are relatively prime(having no comoon divisor other than 1) to n.
It was given that cost of one unit of bamboo is 1 Xukha(a form of currency) and each student has to buy one bamboo.Now,since our goal is to minimize total cost,so our goal would be to buy the smallest bamboo possible for each student.

Students can buy a bamboo with a score greater than or equal to his/her lucky number. So our approach would be to find the least sized length of bamboos whose score is atleast equal to the lucky numbers and we can find out the least sized length of bamboo through finding out the next immediate prime number present from the lucky number. There are a few reasons for making such a claim.The reasons are:

- Bamboo size will always be greater than the lucky number for each student.
- For a lucky number of 8, there are no numbers smaller than 11 that have a count of relatively prime number of at least 8. So our score would be 10(1,2,3,4,5,6,7,8,9,10) here which is a greater value than the lucky number. So we have to take a bamboo size of 11 for the student having a lucky number of 8.

### Resources:
Here are some resources of **Sieve of Eratosthenes** so that you can have a deeper understanding on this topic and learn to solve problems from this topic using these resources:
- [CP-Algorithm](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#segmented-sieve)
- [Shafayet's Blog](https://www.shafaetsplanet.com/?p=624)

If you are still stuck with this problem, check the code below:

### C++
```cpp
#include <bits/stdc++.h>
using namespace std;
bitset<6000008> mark;
void sieve()
{
    mark[0] = mark[1] = 1;
    for (int i = 4; i <= 4e6; i += 2)
        mark[i] = 1;
    for (int i = 3; i * i <= 4e6; i += 2)
    {
        if (!mark[i])
        {
            for (int j = i * i; j <= 4e6; j += 2 * i)
                mark[j] = 1;
        }
    }
}
int main()
{
    sieve();
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            num++;
            for (int j = num;; j++)
            {
                if (mark[j] == 0)
                {
                    ans += j;
                    break;
                }
            }
        }
        cout << "Case " << k << ": " << ans << " " << "Xukha" << endl;
    }
}
```
