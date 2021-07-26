class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, 0);
        
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int child: rooms[cur]) {
                if (!vis[child]) {
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i]) return 0;
        }
        return 1;
    }
};

/*
Input: [[1,3],[3,0,1],[2],[0]]
0 --> 1
|
|
3
*/
