#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
    int t;  cin>>t;
  stack<int> s1;
 stack<int> s2;

while(t--)
    {
    int num;
    cin>>num;

    switch(num)
        {
        case 1:
        {
            int insert;
            cin>>insert;
            s1.push(insert);
            break;
        }
        case 2:
        {
            if(s2.empty())
                {
                while(!s1.empty())
                    {
                s2.push(s1.top());
                s1.pop();
                }
            }

            s2.pop();  
            break;
        }
        case 3:
        {

           if(!s2.empty())
               {
               cout<<s2.top()<<endl;
           }
            else
                {
                while(!s1.empty())
                    {
                    s2.push(s1.top());
                        s1.pop();
                }
                cout<<s2.top()<<endl;
            }
            break;

        }

    }
}

return 0;
}
