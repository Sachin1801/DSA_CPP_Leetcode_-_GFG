class Solution {
private:
    int dp[301];
    int helper(int i, string s, unordered_set<string> &wordDict){
        //base case 
        if(i==s.length()) return dp[i]=1;
        if(dp[i]!=-1) return dp[i];
        string temp;
        for(int j = i; j<= s.size();j++){
            temp += s[j];
            if(wordDict.find(temp)!=wordDict.end()){
                if(helper(j+1,s,wordDict)) return dp[j]=1;
            }
        }
        return dp[i]=0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof dp);
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        return helper(0,s,st);
    }
};