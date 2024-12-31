class Solution {

private:
    bool check(char c){
        if(c=='(' or c=='{' or c=='[')
            return true;
        return false;
    }

    bool check2(char c, char c2){
        if((c==')' and c2 =='(') || (c=='}' and c2 =='{') || (c==']' and c2=='['))
            return true;
        return false;
    }

public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                if(check(s[i])){
                    st.push(s[i]);
                }else{
                    return false;
                }
            }else{
                if(check(s[i])){
                    st.push(s[i]);
                }else{
                    if(check2(s[i],st.top())){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        return st.size()==0;
    }
};