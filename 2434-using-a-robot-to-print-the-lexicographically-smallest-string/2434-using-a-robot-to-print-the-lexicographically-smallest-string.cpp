class Solution {
public:
    string robotWithString(string s) {
        map<char,vector<int>> m;
        int n = s.length();
        for(int i=0;i<n;i++){
            m[s[i]].push_back(i);
        }
        vector<bool> visited(26,0);
        int i = 0;
        stack<char> st;
        string ans ="";
        for(auto &pair: m){
            if(i == n) break;
            char ch = pair.first;
            visited[ch-'a']=true;
            vector<int> &v = pair.second;
            for(int j = 0; j<v.size();j++){
                while(i < n && i<=v[j]){
                    st.push(s[i]);
                    i++;
                }
                while(!st.empty() && (st.top() == ch || visited[st.top()-'a']== true)){
                    ans += st.top();
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};