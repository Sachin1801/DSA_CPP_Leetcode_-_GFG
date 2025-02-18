class Solution {
private:
    void helper(int idx, string s, vector<vector<string>> &res, vector<string> &path){
        if(idx == s.length()){
            res.push_back(path);
            return;
        }
        for(int i=idx; i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                helper(i+1, s, res,path);
                path.pop_back();
            }
        }
    }

    bool isPalindrome( string s, int start, int end){
        while(start <= end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path ;
        helper(0,s,res,path);
        return res;
    }
};