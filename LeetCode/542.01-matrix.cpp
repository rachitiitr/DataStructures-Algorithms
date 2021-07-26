using loc = pair<int, int>;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        // dis[i][j] = nearest distance (i, j) to nearest 0
        
        queue<loc> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()) {
            // loc cur = q.front(); 
            // int x = cur.first, y = cur.second;
            auto [x, y] = q.front(); // current loc in mat, structured binding in C++
            q.pop();
            // (2,3) -> (1, 3) up, (3, 3) down, +1 -1 on the columns as well
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    // valid neighbour
                    if (dis[nx][ny] == INT_MAX) {
                        dis[nx][ny] = 1 + dis[x][y];
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return dis;
    }
};

/*
// BFS gives the shortest path in unweighted graphs

n * m <--- 0s and 1s
    
    for every 1:
        compute the smallest distance to 0
            
dis[i][j] = 0 where mat[i][j] = 0
            
queue<> Q = {(i,j)} where mat[i][j] = 0;

cur = Q.front();

for(nei in neighbors(cur)) {
    dis[nei] = 1 + dis[cur] if nei is not alreaady in queue
}

*/

