class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length()==1)
            return false;
        if(s[0]==')' and locked[0]=='1')
            return false;
        int n = s.length();
        if(s[n-1]=='(' and locked[n-1]=='1')
            return false;
        if(n%2!=0)
            return false;
        int open=0,close=0,wild_c=0;
        for(int i=0;i<n;i++){
            if(locked[i]=='0')
                wild_c++;
            else if(s[i]==')')
                close++;
            else
                open++;
            if(close>open+wild_c){
                return false;
            }
        }
        open = close = wild_c = 0;
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0')
                wild_c++;
            else if(s[i]=='(')
                open++;
            else
                close++;
            if(open > close + wild_c)
                return false;
        }
        return true;
    }
};