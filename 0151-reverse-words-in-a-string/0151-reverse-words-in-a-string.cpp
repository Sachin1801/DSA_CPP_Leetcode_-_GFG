class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp ="";
        for(int i=0;i<s.length();++i){
            if(s[i]==' '){
                if(temp.length()!=0){
                    st.push(temp);
                    temp ="";
                }
            }else{
                temp += s[i];
            }
        }
        if(temp.length()!=0){
            st.push(temp);
            temp= "";
        }
        char space =' ';
        while(!st.empty()){
            temp += st.top();
            st.pop();
            if(!st.empty())
                temp += space;
        }
        return temp;
    }
};