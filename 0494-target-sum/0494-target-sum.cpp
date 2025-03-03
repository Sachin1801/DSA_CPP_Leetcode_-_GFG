class Solution {
private:

    int findways(vector<int> &arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        
        if(arr[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        if(arr[0]!=0 && arr[0] <=target) dp[0][arr[0]]=1;
        
        for(int ind =1; ind<n;ind++){
            for(int sum =0;sum <=target;sum++){
                int notTake = dp[ind-1][sum];
                int take = 0;
                if(arr[ind]<=sum) take = dp[ind-1][sum-arr[ind]];
                dp[ind][sum]=(take+ notTake);
            }
        }
        
        return dp[n-1][target];
    }
    
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int totalsum= accumulate(arr.begin(),arr.end(),0);
        if(totalsum - d < 0 || (totalsum - d)%2!=0) return 0;
        
        return findways(arr,(totalsum-d)/2);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return countPartitions(nums,target);
    }
};