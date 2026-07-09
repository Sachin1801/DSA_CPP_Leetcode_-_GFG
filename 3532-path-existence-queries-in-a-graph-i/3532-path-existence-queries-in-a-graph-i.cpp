#include<typeinfo>

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n);
        int ids = 0;

        for(int i = 1; i < n; i++ ){
            if( nums[i] - nums[i-1] > maxDiff ){
                ids++;
            }
            comp[i]= ids;
        }

        vector<bool> ans;
            
        for(auto& q: queries){
            int u = q[0];
            int v = q[1];

            
            ans.push_back(comp[u] == comp[v]);
            
        }
        return ans;
    }
};