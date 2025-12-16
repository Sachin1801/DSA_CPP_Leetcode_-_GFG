class Solution {
public:

    int f(int i, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(i >= prices.size()) return 0;

        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

        int profit = 0;
        //case 1 : can buy
        if(buy ==1 ){
            profit = max( f(i+1, 0,cap, prices,dp) - prices[i], f(i+1, buy, cap, prices, dp));
        }else{
            //case 2 : can sell
            profit = max( prices[i] + f(i+1,1, cap-1,prices, dp ), f(i+1, buy, cap, prices, dp));
        }
        return dp[i][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,dp);
    }
};