const int N = 20;
vector<int> g[N];
using path = vector<int>;
set<path> get_all_paths(int src, int tar) {
    // cout << src << endl;
    if(src == tar) return { {tar} };
    set<path> ans = {};
    for(int v: g[src]) {
        auto rem_paths = get_all_paths(v, tar);
        for (path p: rem_paths) {
            p.push_back(src);
            ans.insert(p);
        }
    }
    return ans;
}


class Solution {
    
public:
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // paths from 0 to 4
        // iterate on children v of 0
        // find paths from child v to 4
        // [0,1,3,4]
        int n = graph.size();
        
        if(n == 0) return {};
        for(int i = 0; i < n; i++) g[i].clear();
        
        for(int i = 0; i < n; i++) {
            for(int v: graph[i]) {
                g[i].push_back(v);
            }
        }
        
        vector<path> ans = {};
        set<path> paths = get_all_paths(0, n-1);
        
        
        // O(# of paths * avg_size of path)
        for(auto p: paths) {
            reverse(p.begin(), p.end());
            ans.push_back(p);
        }
        
        return ans;
    }
};
