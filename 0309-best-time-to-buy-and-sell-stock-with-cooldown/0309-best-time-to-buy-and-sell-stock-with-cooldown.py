class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)

        if n == 1:
            return 0

        dp = {} # storing key : {i, buy/sell: bool} , value : maxProfit

        def solve(i, buying):
            if i >= n:
                return 0
            
            if (i,buying) in dp:
                return dp[(i,buying)]

            cooldown = solve(i+1, buying)
            if(buying):
                buy = solve(i+1, not buying) - prices[i]
                dp[(i,buying)] = max(buy, cooldown)
            else:
                sell = solve(i+2, not buying) + prices[i]
                dp[(i,buying)] = max(sell, cooldown)
            return dp[i,buying]

        return solve(0,True)
        
        

        