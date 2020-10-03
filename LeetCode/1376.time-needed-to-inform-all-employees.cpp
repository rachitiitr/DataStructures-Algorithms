class Solution {
public:
    vector<int>visited;
    long long int dfs(vector<vector<int>>& adj, vector<int>& informTime, int src, int n)
    {
        long long int count = 0;
        for(int i=0;i<adj[src].size();i++)
        {
            count = max(count,dfs(adj, informTime, adj[src][i], n));
        }
        return (informTime[src]+count);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        }
        long long int time;
        visited.resize(n,0);
        visited[headID] = 1;
        time= dfs(adj, informTime, headID, n);
        return time;
    }
};
