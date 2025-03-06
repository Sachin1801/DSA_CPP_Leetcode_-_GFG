class Solution {
public:
    #define vii vector<vector<int> >
    
    int edit_distance(string &s1, string &s2,int n, int m,vii &dp)
{
	if(n==0) return dp[n][m] = m;
	if(!m) return dp[n][m] =n; // !m is same as m==0
    
    if(dp[n][m]!=-1) return dp[n][m];
	if(s1[n-1]!=s2[m-1])
	{
		return dp[n][m] = min(edit_distance(s1,s2,n-1,m,dp),
			min(edit_distance(s1,s2,n,m-1,dp),
				edit_distance(s1,s2,n-1,m-1,dp))) + 1;
	} 
	else{
		return dp[n][m] = edit_distance(s1,s2,n-1,m-1,dp);
	}
}
    
    int minDistance(string word1, string word2) {
        int n= word1.length();
        int n2= word2.length();
        vii dp(n+1,vector<int>(n2+1,-1));
        return edit_distance(word1,word2,n,n2,dp);
    }
};