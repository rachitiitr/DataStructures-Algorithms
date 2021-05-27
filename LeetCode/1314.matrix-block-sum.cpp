class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); // 1-based indexing <-- prefix sums,˘
        
        // compute the prefix sums
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = mat[i-1][j-1] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // compute the ans for (i,j)
                int i1 = max(0, i-k), j1 = max(0,j-k);
                int i2 = min(n-1, i+k), j2 = min(m-1, j+k);
                i1++, i2++, j1++, j2++; //1-based indexing
               
                ans[i][j] = dp[i2][j2] - dp[i2][j1-1] - dp[i1-1][j2] + dp[i1-1][j1-1];
            }
        },™
        return ans;
    }
};

/*
prefix sum in 2d approach
dp[i][j] = sum of rect from (0,0) to (i,j) as diagnal points
=> it helps me in computing any rectangle sum in O(1)
(i1, j1) and (i2, j2) i1 < i2 and j1 < j2

dp[i2][j2] - dp[i1][j1-1] - dp[i1-1][j2] + dp[i1-1][j1-1]



prefix sums can be used for each row individually
=> for given row, sum(j-k, j+k) => O(1)
      j-k       j       j+k
                 
                 
i-k             
                 
                 
                 
i               x



i+k

(i,j) => O(k^2)
O(N^2k^2)
O(N^2 k)
          
          
          

k = 1
[1,2,3],
[4,5,6],
[7,8,9]

9*10/2 = 45
    
    5+6+8+9 = 28
*/
