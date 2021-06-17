int f(int i, int j, int n) {
    return i * n + j;
}
const int N = 1000;
int deg[N];
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int e = 4 * n;
        int n_dash = n+1; // # of nodes / points in each row in new graph
        int v_dash = n_dash * n_dash;
        // vector<vector<int>> corners = { 
        //     {0, 0}, {0, n_dash-1},
        //     {n_dash-1, 0}, {n_dash-1, n_dash-1}
        // };
        for(int i = 0; i < n_dash; i++) {
            int id = f(0, i, n_dash);
            // cout << "Corner " << id << endl;
            deg[id]++;
            
            // right most column
            id = f(i, n_dash-1, n_dash);
            deg[id]++;
            
            // bottom row
            id = f(n_dash-1, i, n_dash);
            deg[id]++;
            
            // left most column
            id = f(i, 0, n_dash);
            deg[id]++;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                char c = grid[i][j];
                if(c == '/') {
                    int u = f(i, j+1, n_dash), v = f(i+1, j, n_dash);
                    // cout << u << " " << v << endl;
                    deg[u]++, deg[v]++;
                    e++;
                }
                else if (c == '\\') {
                    int u = f(i, j, n_dash), v = f(i+1, j+1, n_dash);
                    // cout << u << " " << v << endl;
                    deg[u]++, deg[v]++;
                    e++;   
                }
            }
        }
        for(int i = 0; i < n_dash; i++) {
            for(int j = 0; j < n_dash; j++) {
                int id = f(i, j, n_dash); // node id in new vertex
                if(deg[id] == 0) v_dash--;
                deg[id] = 0; // clear the deg array for next run
            }
        }
        return e - v_dash + 1; 
    }
};
        
/*
(0,0)            (0,n_dash-1)
(n_dash-1, 0)    (n_dash-1, n_dash-1)
x--x--x
|    /|
x  x  x
| /   |
x--x--x

f = e - v + 1
v is not all nodes - remove the nodes with 0 edges
edges and vertices --- # of regions / cycles
*/

