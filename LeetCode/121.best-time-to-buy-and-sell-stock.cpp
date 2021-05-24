class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0, suff_max = prices.back();
        for(int i = n-2; i >= 0; i--) {
            ans = max(ans, suff_max - prices[i]);
            suff_max = max(suff_max, prices[i]);
            /*
            for(int j = i+1; j < n; j++) {
                ans = max(ans, prices[j] - prices[i]);
            }
            */
        }
        return ans;     
    }
};
/*
        <---100--->
_ _ _ 120 _ _ _ _ _ _ 
    i            
    
    max = 100
    */


