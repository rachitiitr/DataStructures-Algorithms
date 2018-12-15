//https://www.youtube.com/watch?v=hZkb_Dqu7YY
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int maxIndexReachable = nums[0];
        int ans = 1, lim = nums[0]; 
        
        for(int i = 1; i < n; i++)
        {
            if(i > lim) {
                ans++;
                lim = maxIndexReachable;
            }
            maxIndexReachable = max(maxIndexReachable, i+nums[i]);
        }
        
        return ans;
    }
};
