ass Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {  
        vector<int> incoming(n+1, 0); //O(n) extra space
        
        for(auto edge: edges) { // O(M) where M is # of edges
            int u = edge[0], v = edge[1];
            // u --> v
            incoming[v]++; // O(logn) if you use maps
        }
        
        vector<int> ans = {}; // # of nodes with 0 incoming edges
        for(int i = 0; i < n; i++) {
            if (incoming[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};
