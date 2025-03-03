class Solution {
private:
    bool f(int idx, int sum, int rem, vector<int> &nums, int n,vector<vector<int>> &dp){
        if(idx == n){
            return 0;
        }
        if(sum == rem) return dp[idx][sum] = 1;
        if(dp[idx][sum]!=-1) return dp[idx][sum];

        bool notTake = f(idx+1, sum, rem, nums,n,dp);
        bool Take =false;
        if(nums[idx]+sum <= rem - nums[idx]) Take = f(idx+1, sum+nums[idx], rem - nums[idx],nums,n,dp);

        return dp[idx][sum] = Take | notTake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int rem = accumulate(nums.begin(),nums.end(),0);
        int sum = 0;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(rem,-1));
        return f(0,sum,rem,nums,n,dp);
    }
};