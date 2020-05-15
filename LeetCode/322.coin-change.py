#
# @lc app=leetcode id=322 lang=python3
#
# [322] Coin Change
#

# @lc code=start
INF = 10 ** 7
class Solution:
    def coinChange(self, C: List[int], S: int) -> int:
        noCoins = len(C)
        dp = [[INF for _ in range(noCoins+1)] for _ in range(S+1)]
        # dp[i][j] is min coins needed to make sum "i" when first "j" coins are available
        dp[0][0] = 0 # no coin needed to make 0
        for i in range(0, S+1):
            for j in range(1, noCoins+1):
                curCoin = C[j-1] # 0-based indexing
                
                # Case A: I don't take jth coin
                dp[i][j] = dp[i][j-1]
                
                # Case B: I take jth coin
                if curCoin <= i:
                    dp[i][j] = min(dp[i][j], 1 + dp[i-curCoin][j])
        return dp[S][noCoins] if dp[S][noCoins] != INF else -1
        
# @lc code=end

