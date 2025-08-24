class Solution {
    private:
        int max_profit(vector<vector<vector<int>>> &dp,vector<int>& prices, int i, int buy, int cap,int n){
            
            if(i == n || cap == 0) return 0;
            // if(cap ==0 )return dp[i][buy][cap]==0;
            
            if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
            
            
            
            if(buy==1){
                return dp[i][buy][cap]= max((-prices[i] + max_profit(dp,prices,i+1,0,cap,n)), (0 + max_profit(dp,prices,i+1, 1, cap,n)));
            }
                //sell
               return dp[i][buy][cap]= max((prices[i] + max_profit(dp,prices,i+1, 1, cap-1,n)), (0 + max_profit(dp,prices,i+1, 0,cap,n)));
            
             
        }
        
    
    
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        
        // buy -> 1
        // sell -> 0 
        // ind i =0 .... n-1
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return max_profit(dp,prices,0,1,k,n);
    }
};