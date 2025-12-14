// Last updated: 12/14/2025, 4:15:38 PM
class Solution {
public:
    string clearDigits(string s) {
        deque<char> q;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                q.pop_back();
            }
            if(isalpha(s[i])){
                q.push_back(s[i]);
            }
        }
        string ans = "";
        while(!q.empty()){
            ans += q.front();
            q.pop_front();
        }
        return ans;
    }
};