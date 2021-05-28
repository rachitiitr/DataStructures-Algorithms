class Solution {
    vector<int> nums;
    set<int> s; // what all indices are there in recursion stack
    
    bool isPossible(int cur) { // can we reach a zero from cur index
        if (s.find(cur) != s.end()) {
            return false; // we detected a cycle / deadlock
        }
        if(0 <= cur && cur < nums.size()) {
            if(nums[cur] == 0) return true;
            s.insert(cur);
            bool ans = false;
            if (isPossible(cur + nums[cur])) ans = true;
            else if (isPossible(cur - nums[cur])) ans = true;
            s.erase(cur);
            return ans;
        }
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        //dp[i] <-- is it possible to reach a zero from i
        nums = arr;
        return isPossible(start);
    }
};
