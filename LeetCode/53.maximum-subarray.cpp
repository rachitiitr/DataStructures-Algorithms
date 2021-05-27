class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        
        // vector<int> dp(n+1, 0); // O(N) extra space
        // dp[i] = max subarray sum starting from index i
        // mandate to pick something
        int nextMax = 0;
        for(int i = n-1; i >= 0; i--) {
            // dp[i] = max(nums[i] + dp[i+1], 0)
            // dp[i] = nums[i] + max(dp[i+1], 0);
            int curMax = nums[i] + max(nextMax, 0);
            ans = max(ans, curMax);
            nextMax = curMax;
        }
       
        return ans;
    }
};

/*
_ _ _ _ _ 100 _ _ _ _ _ 
        i ^
        dp[i] = max(nums[i] + dp[i+1], 0)
*/
