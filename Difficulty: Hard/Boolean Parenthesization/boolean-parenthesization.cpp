// User function Template for C++
#define mod 1e7
class Solution {
  public:
  
    int f(int i, int j, int isTrue, string &s,vector<vector<vector<int>>> &dp){
        if(i>j) return 0;
        if(i==j){
            //only one char which is either T or F
            if(isTrue == 1 ) return s[i]=='T';
            else return s[i]=='F';
        }
        
        if(dp[i][j][isTrue] != -1 )return dp[i][j][isTrue];
            
        int ways = 0;
        for(int idx = i+1;idx<=j-1;idx+=2){
            int leftTrue = f(i,idx-1,1,s,dp);
            int leftFalse = f(i,idx-1,0,s,dp);
            int rightTrue = f(idx+1,j,1,s,dp);
            int rightFalse = f(idx+1,j,0,s,dp);
                
            if(s[idx] =='&'){
                if(isTrue)
                    ways = (ways + (leftTrue *rightTrue));
                else
                    ways = ways + (leftTrue * rightFalse) + (leftFalse * rightTrue) + ( leftFalse * rightFalse );
            }else if(s[idx] =='|' ){
                if(isTrue)
                    ways = ways + (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse *rightTrue);
                else
                    ways += (leftFalse * rightFalse);
            }else{
                if(isTrue)
                    ways = ways + (leftTrue * rightFalse) + (leftFalse * rightTrue);
                else
                    ways = ways + (leftTrue * rightTrue) + (leftFalse * rightFalse);
            }
        }
        return dp[i][j][isTrue]=ways;
    }
  
    int countWays(string &s) {
        // code here
        
        int n = s.length();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        
        return f(0,n-1,1,s,dp);
        
    }
};