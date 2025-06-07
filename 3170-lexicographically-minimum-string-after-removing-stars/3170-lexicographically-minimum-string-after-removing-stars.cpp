class Solution {
public:
    string clearStars(string s) {
        map<char,vector<int>> m;
        int n = s.length();
        cout<<n<<endl;
        for(int i =0;i<n;i++){
            if(s[i]=='*'){
                auto it = m.begin();
                it->second.pop_back();
                if(it->second.size()==0){
                    m.erase(it->first);
                }
            }else{
                m[s[i]].push_back(i);
            }
        }

        
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
        for(const auto&p: m){
            char ch  = p.first;
            for(auto idx: p.second){
                pq.push({idx,ch});
            }
        }
        string ans;
        while(!pq.empty()){
            ans += pq.top().second;
            pq.pop();
        }
        return ans;
    }
};