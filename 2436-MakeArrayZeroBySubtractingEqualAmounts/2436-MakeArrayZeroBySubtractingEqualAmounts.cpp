// Last updated: 12/14/2025, 4:16:44 PM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s;
        for(auto x: nums)
        {
            if(x!=0)
            {
                s.insert(x);
            }
        }
        return s.size();
    }
};