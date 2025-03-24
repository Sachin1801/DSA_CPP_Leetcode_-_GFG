class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(auto str: strs){
            string curr = str;
            sort(curr.begin(),curr.end());
            m[curr].push_back(str);
        }
        int n = m.size();
        vector<vector<string>> ans(n);
        int i=0;
        for(auto &pair: m){
            vector<string> temp = pair.second;
            for(int j=0;j<temp.size();j++){
                ans[i].push_back(temp[j]);
            }
            i++;
        }
        return ans;
    }
};