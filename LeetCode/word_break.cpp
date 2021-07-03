// Word break memoization solution

class Solution {
public:
    unordered_map<string,int> mpp;
    int dp[501];
    
    bool get(string s,int index){
        if(index==s.size())return true;
        if(dp[index]!=-1)return dp[index];
        string tmp="";
        bool ok=false;
        for(int i=index;i<s.size();i++){
            tmp+=s[i];
            if(mpp[tmp]>0){
                ok=(ok|get(s,i+1));
            }
        }
        return dp[index]=ok;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto el:wordDict)mpp[el]++;
        for(int i=0;i<501;i++)dp[i]=-1;
        bool ans=get(s,0);
        return ans;
    }
};