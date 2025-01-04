class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length())
            return "0";
        stack<int> s;
        for(int i=0;i<num.size();i++){
            int n = num[i]-'0';
            while(!s.empty() and k > 0 and s.top() > n){
                s.pop();
                k--;
            }
            s.push(n);
        }
        while(k>0){
            k--;
            s.pop();
        }
        if(s.empty())
            return "0";
        string ans="";
        while(!s.empty())
        {
            ans += to_string(s.top());
            s.pop();
        }
        while(ans.length()>0 and ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans.length()==0 ? "0" : ans;
    }
};