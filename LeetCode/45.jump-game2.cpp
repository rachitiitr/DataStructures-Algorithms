class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX - 1); 
        // dp[i] = min steps to reach the end of array if we are at ith index
        dp[n-1] = 0; 
        for(int i = n-2; i >= 0; i--) {
            for(int j = i+1; j <= i+nums[i]; j++) {
                if(j >= n) break;
                dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
        
        return dp[0];
    }
};

/*
Find: min steps to reach the end of array

Given: i -> we can jump a length of nums[i]
0 index

_ _ _ _ 7 _ _ _ _ _ _ _ _ _
        i x x x x x x x
        
dp[i] = min steps to reach the end of array if we are at ith index

for(j=i+1; j<=i+7; j++) {
    dp[i] = min(dp[i], 1 + dp[j]);
}

return dp[0]
*/
