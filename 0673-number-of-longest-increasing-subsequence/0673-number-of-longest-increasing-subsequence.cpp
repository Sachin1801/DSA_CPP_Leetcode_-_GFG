class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi =1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    //inherit count
                    cnt[i] =cnt[j];
                }
                else if(nums[j]< nums[i] && dp[j]+1 == dp[i]){
                    //increase count
                    cnt[i] += cnt[j];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int Cnt=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)
                Cnt+=cnt[i];
        }
        
        return Cnt;
    }
};