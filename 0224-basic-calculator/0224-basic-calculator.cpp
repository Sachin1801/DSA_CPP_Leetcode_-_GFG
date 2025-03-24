class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long curr = 0;
        int res = 0;
        int sign = 1;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                curr = curr * 10 + (s[i]-'0');
            } else if (s[i] == '+' || s[i] == '-') {
                res += sign * curr;
                sign = (s[i] == '+') ? 1 : -1;
                curr = 0;
            }
            else if(s[i]=='('){
                st.push(res);
                st.push(sign);
                sign =1;
                res=0;
            }else if(s[i]==')'){
                res += sign* curr;
                curr = 0;
                res *= st.top();
                st.pop();
                res+= st.top();
                st.pop();
                
            }
        }
        return res + sign * curr;
    }
};