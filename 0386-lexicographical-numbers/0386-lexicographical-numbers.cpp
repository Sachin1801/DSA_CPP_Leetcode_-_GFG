class Solution {
public:
    vector<int> lexicalOrder(int n) {
        priority_queue<string,vector<string>,greater<string>> pq;

        for(int i=1;i<=n;i++){
            string s= to_string(i);

            pq.push(s);
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(stoi(pq.top()));
            pq.pop();
        }
        return ans;
    }
};