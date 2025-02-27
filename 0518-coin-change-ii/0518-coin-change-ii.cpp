#define ll long long

class Solution {
private:
    int func(int idx, int tar, vector<int> &coins,vector<vector<ll>> &dp ){
        if(idx == 0)
            return (tar%coins[idx]==0);
        
        if(dp[idx][tar]!=-1) return dp[idx][tar];
        ll notTake = func(idx-1,tar,coins, dp);
        ll Take =0;
        if(coins[idx] <= tar){
            Take = func(idx, tar-coins[idx],coins,dp);
        }
        return dp[idx][tar]= notTake + Take;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<ll>> dp(n, vector<ll>(amount+1,-1));
        return func(n-1,amount, coins, dp);
    }
};