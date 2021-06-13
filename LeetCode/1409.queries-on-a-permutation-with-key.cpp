class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        unordered_map<int, int> pos, rev_pos; // pos[3] - 10 => 3 occurs at index 10
        for(int i = 1; i <= m; i++) {
            pos[i] = i-1, rev_pos[i-1] = i;
        }
        
        vector<int> ans = {};
        for(int q: queries) {
            ans.push_back(pos[q]);
            // increment the pos of all nos from 0 to pos[q]-1
            for (int i = pos[q]-1 ; i >= 0; i--) {
                int cur = rev_pos[i];
                pos[cur] = i+1; // shift to right side
                rev_pos[i+1] = cur;
            }
            pos[q] = 0;
            rev_pos[0] = q;
        }
        return ans;
    }
};
// 1,2,3,4,5
// 3,1,2,4,5

// _ _ _ _ _ _ _ _ _ _ _ 
          // ^ 