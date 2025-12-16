class Solution {
public:

    int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(j < 0 && i>=0) return i+1;
        if(i < 0 && j >=0) return j+1;
        if(i < 0 && j < 0) return 0;

        if(dp[i][j]!= -1) return dp[i][j];
        //case 1 : if the current char match
        int total = 1e9;
        if(word1[i]==word2[j]){
            total = f(i-1,j-1,word1,word2,dp);
        }else{
            //case 1: we can delete and move on 
            //case 2: we can insert and move on 
            //case 3: we can replace and move on
            total = 1 + min ( f(i-1,j,word1,word2,dp),min( f(i,j-1,word1,word2,dp), f(i-1,j-1,word1,word2,dp)));
        }
        return dp[i][j] = total;
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return f(n-1,m-1,word1,word2,dp);
    }
};