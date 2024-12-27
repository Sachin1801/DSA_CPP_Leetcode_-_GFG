class Solution {
private:

    vector<string> generateALL(int n, int open, int close, string s, vector<string> &ans){
        if(open==n and close ==n){
            ans.push_back(s);
            return ans;
        }
        if(open==0){
            generateALL(n,open+1,close,s+"(",ans);
        }else{
        if(open < n){
            generateALL(n,open+1,close,s+"(",ans);
        }
        if(close < open){
            generateALL(n,open,close+1,s+")",ans);
        }
        }
        return ans;
    }

public:
    vector<string> generateParenthesis(int n) {
        if(n==1){
            return {"()"};
        }
        vector<string> ans;
        return generateALL(n,0,0,"",ans);
        
    }
};