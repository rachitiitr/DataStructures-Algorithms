class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> allowed(n, 0); // O(n) extra space
        allowed[0] = 1;
        for (int i = 0; i < n; i++) {
            if (allowed[i]) {
                for(int j = min(n-1, i+nums[i]); j >= i+1; j--) {
                    if(allowed[j]) break;
                    allowed[j] = 1;
                }
            }
        }
        return allowed[n-1];
    }
};

/*
_ _ _ 7 _ _ 1 1 1 1 1 _ 
      i x x x x x x x
      
if i is allowerd and 100
      i+1,i+2,...,i+100 <-- allowed
      
whether n-1 is allowed <-- true / false
      
   */   
      
     
