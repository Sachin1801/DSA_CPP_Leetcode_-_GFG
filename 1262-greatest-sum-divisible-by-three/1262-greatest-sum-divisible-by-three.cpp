class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);  // Stores max sum for each remainder (0, 1, 2)

        for (int num : nums) {
            vector<int> temp(dp);  // Make a copy to prevent overwriting in the same iteration

            for (int sum : temp) {
                int newSum = sum + num;
                int remainder = newSum % 3;
                dp[remainder] = max(dp[remainder], newSum);
            }
        }
        return dp[0];  // Max sum divisible by 3
    }
};
