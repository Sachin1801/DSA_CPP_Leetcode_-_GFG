class Solution {
int func(int idx, int prevIdx, vector<vector<int>> &dp, int n, vector<int> &nums ){
    if(idx==n) return 0;

    if(dp[idx][prevIdx+1]!=-1) return dp[idx][prevIdx+1];
    int len = func(idx+1,prevIdx, dp, n,nums);
    if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
        len = max(len,1 + func(idx+1,idx, dp, n,nums));
    }
    return dp[idx][prevIdx+1]= len;
}

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));

        return func(0,-1,dp,n,nums);
    }
};