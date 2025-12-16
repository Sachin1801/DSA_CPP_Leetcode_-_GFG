class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<2;j++){
        //         dp[i][j][0]=0;
        //     }
        // }

        for(int i = n-1; i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<=k;cap++){
                    // if(i==n) continue;
                    if(buy ==1 ){
                        dp[i][buy][cap] = max( dp[i+1][0][cap] - prices[i], dp[i+1][1][cap]);
                    }else{
                        //case 2 : can sell
                        dp[i][buy][cap] = max( prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }
                    // dp[i][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};
