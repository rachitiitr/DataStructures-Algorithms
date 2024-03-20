#include <bits/stdc++.h>
using namespace std;

string LongestWord(string sen) {
  
  // code goes here  
  string ans="";
  string currStr="";


  for(int i=0; i<sen.size(); i++){
    
    if(sen[i] >= 'a' && sen[i] <= 'z'){
      currStr += sen[i];
    }else{
      if(currStr.size() > ans.size()){
        ans = currStr;
        currStr = "";
      }
    }
  }

  if(currStr.size() > ans.size())
    ans = currStr;

  return ans;

}



int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cout << LongestWord("fun&!! time");

    string s = "fun&!! time";

    
    return 0;    

}