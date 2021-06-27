// CPP program to generate power set 
#include <bits/stdc++.h> 
using namespace std; 
  
// str : Stores input string 
// curr : Stores current subset 
// index : Index in current subset, curr 
void powerSet(string str, int index = 0, 
              string curr = "") 
{ 
    int n = str.length(); 
  
    // base case 
    if (index == n) { 
        cout << curr << endl; 
        return; 
    } 
  
    // Two cases for every character 
    // (i) We consider the character 
    // as part of current subset 
    // (ii) We do not consider current 
    // character as part of current 
    // subset 
    powerSet(str, index + 1, curr + str[index]); 
    powerSet(str, index + 1, curr); 
} 
  
// Driver code 
int main() 
{ 
    string str = "abc"; 
    powerSet(str); 
    return 0; 
}