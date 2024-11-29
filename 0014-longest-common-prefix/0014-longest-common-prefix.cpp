class Solution {
public:

    string calculate(string curr, string test){
        int len = min(curr.length(),test.length());
        string ans ="";
        for(int i=0;i<len;++i){
            if(curr[i]!=test[i])
                return ans;
            else{
                ans+=test[i];
            }
        }
        return ans;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)
            return strs[0];
        string current = strs[0];
        string ans = current;
        for(int i=1;i<strs.size();++i){
            current = ans;
            ans = calculate(current,strs[i]);
        }
        return ans;
    }
};