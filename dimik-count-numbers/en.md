# Counting Numbers

**Tutorial**
As the question states, there are multiple numbers given in each **Testcase**. We have to count how many numbers are there.

A simple approach to solving this can be taking each line as a string **S** and counting the number of  whitespaces that has a non-whitespace character **before or after**  it. 

Suppose length of **S** is **n**.  We count number of index **i** such that  **0<i<n** and **S<sub>i-1</sub>**  is whitespace  and **S<sub>i</sub>** is not a whitespace.
Lastly, if the **S** starts with a non-whitespace character, we increment the count by 1.
We can repeat this process for each line.

**Solution in C++**
```
#include<bits/stdc++.h>

using namespace std;

int main(){ 
    int t;
    cin >> t; // Input the number of testcases
    
    while(t--){
      cin >> ws; // To clear The buffer
      string s;
      getline(cin,s); // Input each line as a string

      int counter = 0; // initially we set the counter to zero

      for(int i = 1;i < s.size();i++){
        if(s[i-1] == ' ' && s[i] != ' ') counter++;
      }
      if(s[0] != ' ') counter++;

      cout << counter << endl; // output
    }
}
```