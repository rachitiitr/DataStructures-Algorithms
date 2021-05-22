const int N = 70;
set<int> g[N];
bool vis[N];

void fill_cluster_size(int u, int &cluster_size) {
    vis[u] = 1;
    // cout << "dfs::at couple " << u << endl;
    cluster_size++;
    for(int v: g[u]) {
        if(!vis[v]) {
            fill_cluster_size(v, cluster_size);
        }
    }
}

int get_couple_id(int person) {
    return person / 2;
}


class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        // normalizing the seating arrangement in terms of couple ids
        for(int &x: row) x = get_couple_id(x);
        
        for(int i = 0; i < n; i++) {
            g[i].clear();
            vis[i] = 0;
        }
        
        for(int i = 0; i < row.size(); i += 2) {
            int c1 = row[i], c2 = row[i+1];
            if( c1 == c2 ) continue;
            g[c1].insert(c2);
            g[c2].insert(c1);
            // cout << i << " adding edge in couple " << c1 << " " << c2 << endl;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int cluster_size = 0;
                fill_cluster_size(i, cluster_size);
                ans += cluster_size - 1;
            }
        }
        return ans;
    }
};
/*
    0,3,1,2 -> 0,1,3,2
    easy notation: 0,1,0,1
    - Find a swap that can make two couples happy.
    - 
(0, 1) --- 1st couple --- couple id = 0
(2, 3) --- 2nd couple --- couple id = 1
(4, 5) -- 3rd couple --- couple id = 2
    0,3,5,2,1,4 --> 0,1,2,1,0,2
    
    0---1---2
    \______/

x----y      <--- 1 swap
x----y----z <--- 2 swaps

C couples --- C-1 swaps
*/
