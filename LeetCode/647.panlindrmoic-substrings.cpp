class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        
        // fill this dp
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                // starting from i, and length len
                int j = i + len - 1;
                if (i+1 == j) {
                    dp[i][j] = s[i] == s[j];
                }
                else {
                    dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans += dp[i][j];
        return ans;
    }
};
/*
for substring in all_subtrings;
    if palindrome(substring)
        ans++;


dp[i][j] = substring(i, i+1, ..., j) = is this a palindrome

s[i] == s[j] && dp[i+1][j-1] should be true
*/