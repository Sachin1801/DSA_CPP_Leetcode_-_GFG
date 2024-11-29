class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans ="";
        if(s.length()==1)
            return ans;
        int open_cnt = 1;
        int close_cnt =0;
        int i =0, j=1;
        while(j<s.length()){
            if(s[j]==')'){
                close_cnt++;
                j++;
            }else{
                open_cnt++;
                j++;
            }
            if(close_cnt == open_cnt){
                int temp = i+1;
                while(temp < j-1){
                    ans += s[temp++];
                }
                i = j;
                open_cnt = 1;
                close_cnt = 0;
                j = i + 1;
            }
        }
        return ans;
    }
};