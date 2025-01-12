class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length()%2!=0)
            return false;
        int n = s.length();

        int cnt=0;
        for(int i=0;i<n;i++){
            if(locked[i]=='0' || s[i]=='(')
                cnt++;
            else
                cnt--;
            if(cnt < 0)
                return false;
        }
        cnt =0;
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0' || s[i]==')')
                cnt++;
            else
                cnt--;
            if(cnt<0)
                return false;
        }
        return true;
    }
};