class Solution {
    int dp[46]={0};
public:
    int climbStairs(int n) {
        if(n==0) return dp[0]=1;
        if(n==1) return dp[1]=1;
        int left,right;
        if(dp[n-1]!=0) left = dp[n-1];
        else left = climbStairs(n-1);
        if(dp[n-2]!=0) right = dp[n-2];
        else right = climbStairs(n-2);
        dp[n]=left + right;
        return dp[n];
    }
};