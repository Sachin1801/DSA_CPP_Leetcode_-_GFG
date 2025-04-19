class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string ans = "1";
        deque<pair<char,int>> q;
        q.push_back({'1',1});
        for(int i=2;i<=n;i++){
            string next ="";
            while(!q.empty()){
                pair top = q.front();
                q.pop_front();
                char ch = top.second + '0';
                next.push_back(ch);
                next.push_back(top.first);
            }
            ans = next;
            q.push_back({ans[0],1});
            for(int j=1;j<ans.length();j++){
                if(ans[j]==ans[j-1]){
                    auto &last = q.back();
                    q.pop_back();
                    last.second++;
                    q.push_back(last);
                }
                else{
                    q.push_back({ans[j],1}); 
                }
            }
        }
        return ans;
    }
};