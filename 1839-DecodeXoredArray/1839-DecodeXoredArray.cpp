// Last updated: 12/14/2025, 4:17:13 PM
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for(int i= 0; i<encoded.size();i++)
        {
            ans.push_back(first^encoded[i]);
            first^=encoded[i];
        }
        return ans;
    }
};