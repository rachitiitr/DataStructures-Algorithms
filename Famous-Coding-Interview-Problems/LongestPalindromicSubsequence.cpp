class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
      vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1));
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 1; j <= s.size(); j++)
            {
                if(s[i - 1] == s[s.size() - j])  //imp line 
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[s.size()][s.size()];
    }
 
};

//Time Complexity: O(n^2)
//LeetCode: https://leetcode.com/problems/longest-palindromic-subsequence/
