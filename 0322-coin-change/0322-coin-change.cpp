#define ll long long

class Solution {
private:
    ll func(ll idx, ll tar, vector<int> &coins, vector<vector<ll>> &dp) {
        if (idx == 0) {
            return (tar % coins[0] == 0) ? (tar/coins[0]) : INT_MAX;
        }
        if (dp[idx][tar] != -1) return dp[idx][tar];

        ll notTake = func(idx - 1, tar, coins, dp);
        ll take = INT_MAX;
        if (coins[idx] <= tar){
            int res = func(idx, tar - coins[idx], coins, dp);
            if(res!=INT_MAX){
                take = 1 + res;
            }
        }
        return dp[idx][tar] = min(notTake,take);
    }

public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        vector<vector<ll>> dp(n, vector<ll>(amount + 1, -1));  // Fixed DP initialization
        int result  = func(n - 1, amount, coins, dp) ;
        return result ==INT_MAX ? -1 : result;        
    }
};
