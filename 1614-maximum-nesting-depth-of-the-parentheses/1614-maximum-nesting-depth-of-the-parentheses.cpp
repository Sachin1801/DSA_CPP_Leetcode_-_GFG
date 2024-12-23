class Solution {
public:
    int maxDepth(string s) {
        int cnt =0;
        int maxcnt = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                cnt++;
            }else if(s[i]==')'){
                cnt--;
            }
            maxcnt = max(cnt,maxcnt);
        }
        return maxcnt;
    }
};