class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> followers(n+1, 0); // 1 based indexing
        vector<int> does_follow(n+1, 0);
        
        map<int, int> followers, does_follow; // O(logN)
        
        for(auto edge: trust) {
            int u = edge[0], v = edge[1];
            // person u trusts v
            followers[v]++; // O(1) v/s in maps O(logN) --> O(1)
            does_follow[u] = 1;
        }
        
        vector<int> final_candidates = {};
        for(int i = 1; i <= n; i++) {
            if(followers[i] == n-1 && does_follow[i] == 0) {
                final_candidates.push_back(i);
            }
        }
        
        if(final_candidates.size() != 1) return -1;
        return final_candidates[0];
    }
};
