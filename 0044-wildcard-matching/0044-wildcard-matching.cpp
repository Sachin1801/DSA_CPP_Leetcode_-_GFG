class Solution {

public:
    bool isMatch(string s, string p) {
        int ss = s.size();
        int ps = p.size();
        vector<vector<bool>> dp(ps+1,vector<bool>(ss+1,false));
        dp[0][0]=true;
        for(int j =1; j<=ss;j++){
            dp[0][j]= false;
        }

        for(int i=1;i<=ps;i++){
            int flag = true;
            for(int ii=1;ii<=i;ii++){
                if(p[ii-1]!='*'){
                    dp[i][0] = false;
                    flag= false;
                    break;
                } 
            }
            dp[i][0]=flag;
        }

        for(int i=1;i<=ps;i++){
            for(int j=1;j<=ss;j++){
                if(p[i-1] == s[j-1] || p[i-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1]=='*'){
                    dp[i][j]= dp[i-1][j] | dp[i][j-1];
                }
                else dp[i][j]= false;
            }
        }
        return dp[ps][ss];
    }
};