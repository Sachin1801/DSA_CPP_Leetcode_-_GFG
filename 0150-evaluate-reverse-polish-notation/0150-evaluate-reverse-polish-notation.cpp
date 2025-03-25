class Solution {
private:
    int check(string s){
        bool neg = false;
        int i=0;
        if(s[i]=='-'){
            neg = true;
            i++;
        }
        s = s.substr(i,s.length());
        int num = stoi(s);
        if(neg) num*=-1;
        return num;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="*" || tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="/"){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                if(tokens[i]=="+") st.push(op1+op2);
                else if(tokens[i]=="-") st.push(op1-op2);
                else if(tokens[i]=="*") st.push(op1*op2);
                else st.push(op1/op2);
            }else{
                int num = check(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};