// Last updated: 12/14/2025, 4:16:54 PM
class Solution {
private:
    long long solve(vector<long long> &dp, vector<vector<int>>& questions, int i) {
        if (i >= questions.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        long long pick = questions[i][0] + solve(dp, questions, i + questions[i][1] + 1);
        
        long long skip = solve(dp,questions,i+1);

        return dp[i]= max(pick,skip);

        // not pick
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        
        long long ans  = solve(dp, questions, 0);
        return dp[0];
    }
};