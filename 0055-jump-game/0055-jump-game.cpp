class Solution {
    bool check(vector<int> &nums, int i,vector<int> &dp){
        if(i>=nums.size()-1) return true;

        if(dp[i]!=-1) return dp[i];
        int max_jump= nums[i];
        while(max_jump>0){
            bool can_jump = check(nums,i+max_jump,dp);
            if(can_jump) return dp[i] = true;
            max_jump--;
        }
        return dp[i] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return check(nums,0,dp);
    }
};