#define deb(x1, x2, x3) cout << #x1 << "=" << x1 << " " << #x2 << "=" << x2 << " "<< #x3 << "=" << x3 << endl;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
    // dp[i][j] = max profit for first player when the game is at state [i..j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            dp[i][i] = piles[i]; // 1 size subarrays have been computed
            // if(i+1 < n) {
            //     dp[i][i+1] = abs(piles[i] - piles[i+1]); // subarrays of size 2
            // }
        }
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i < n; i++) {
                int j = i + len - 1;
                if(j >= n) continue;
                // i .. j
                // take the Lth stone
                int choice1 = piles[i] - dp[i+1][j];

                // take the Rth stone
                int choice2 = piles[j] - dp[i][j-1];
                dp[i][j] = max(choice1, choice2);
                // cout << i << " " << j << " " << dp[i][j] << endl;
                // deb(i, j, dp[i][j]);
            }
        }
        
        
        return dp[0][n-1] > 0;
    }
};

/*
5, 3, 4, 5 -> 3,4,5 -> 3,4 -> 3
    
    5
    <---------------------->17 ==> 17 - 5 = 12
    23,....................,17
    23<----------------------> ===> 23-7 = 16
            7 
    
    
state = [L, R] => by how much quantity the first player wins


[0, n-1] => +ve => first player can win -> true
[0, n-1] => -ve => first player cant win -> false
    
// take the Lth stone
choice1 = piles[L] - win(L+1, R)
    
// take the Rth stone
choice2 = piles[R] - win(L, R-1)
    
win(L, R) = max(choice1, choice2);

return win(0, n-1) > 0 
    
*/
    
