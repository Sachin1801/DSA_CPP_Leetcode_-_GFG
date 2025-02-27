class Solution {
private:
    vector<int> dp;
    int ways(int i, string &s){
        if(i>=s.size()) return 1;
        else if(s[i]=='0') return 0;
        else if(i==s.size()-1) return 1;
        else if(dp[i]!=-1) return dp[i];
        else if(s[i]=='1' || (s[i]=='2' && (s[i+1]>='0' and s[i+1]<='6')))
            return dp[i]= ways(i+1,s) + ways(i+2,s);
        return dp[i] = ways(i+1,s);
    }

public:
    int numDecodings(string s) {
        dp.resize(s.size());
        dp.assign(s.size(),-1);
        return ways(0,s);
    }
};