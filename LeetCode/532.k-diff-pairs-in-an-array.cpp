using hashmap = unordered_map<int, int>;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        hashmap cnt;
        for(int x: nums) cnt[x]++;
        
        int ans = 0;
        for(auto p: cnt) { // iterating on unique numbers of the array 
            int x = p.first;
            // check x+k exists in the array
            if(cnt.find(x+k) == cnt.end()) {
                continue;
            }
            ans += (k==0) ? cnt[x+k] >= 2 : cnt[x+k] >= 1;
        }
        
        return ans;
    }
};
