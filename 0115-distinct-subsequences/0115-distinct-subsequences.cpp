class Solution {
public:

    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        //we need to see whether current char is same or not

        int cnt = 0;
        //case 1: if it is same 
        if(s[i] == t[j]){
            // we can either take the current one or skip it 
            cnt = f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);
        }else{
            cnt = f(i-1,j,s,t,dp);
        }

        return dp[i][j]= cnt;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        if(n < m ) return 0;
        if(m==1){
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(s[i]==t[0]) cnt++;
            }
            return cnt;
        }

        return f(n-1,m-1,s,t,dp);
    }
};