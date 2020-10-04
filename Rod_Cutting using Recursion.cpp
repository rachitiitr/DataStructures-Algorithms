#include <bits/stdc++.h> 
using namespace std;  

int rodCutting(int n, int a, int b, int c)
{
    if(n == 0)
      return 0;
    if(n < 0)
      return -1;
    int res = max(max(rodCutting(n-a, a, b, c), rodCutting(n-b, a, b, c)), 
              rodCutting(n-c, a, b, c));
    
    if(res== -1)
      return -1;
    return 1+res;
}

int main()
{
    int n = 25;
    int a = 11, b = 12, c = 13;
    cout << rodCutting(n, a, b, c);
}