class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        auto cmp= [](pair<int,int> p1, pair<int,int> p2){
            return p1.second < p2.second;
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp); 
        for(auto& pair: m){
            pq.push({pair.first,pair.second});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};