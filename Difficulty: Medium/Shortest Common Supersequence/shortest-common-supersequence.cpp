class Solution {
  public:
  
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        //base case
        if(i >= s1.length()) return s2.length() - j;
        if(j >= s2.length() ) return s1.length() - i;
        
        //return if value if dp is present
        if(dp[i][j]!=-1 ) return dp[i][j];
        
        int moves = 0;
        if(s1[i] != s2[j]){
            moves = 1 + min(f(i+1,j,s1,s2,dp), f(i,j+1,s1,s2,dp)); 
        }
        else{
            moves = 1 + f(i+1,j+1, s1, s2, dp);
        }
        return dp[i][j] = moves;
    }
  
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n = s1.length(), m= s2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return f(0,0,s1,s2,dp);
    }
};