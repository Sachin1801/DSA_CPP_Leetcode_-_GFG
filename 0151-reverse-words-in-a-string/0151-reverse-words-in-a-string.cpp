class Solution {
public:
    string reverseWords(string s) {
        int i = s.size()-1;
        string ans = "";
        while(i>=0){
            while(i >=0 && s[i] ==' '){
                i--;
            }
            if(i<0) break;
            int j = i;
            while(j-1>=0 && s[j-1]!=' '){
                j--;
            }
            ans += s.substr(j,i-j+1);
            ans+=' ';
            i = j-1;
        }
        ans.pop_back();
        return ans;
    }
};