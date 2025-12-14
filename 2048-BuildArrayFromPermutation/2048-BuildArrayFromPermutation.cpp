// Last updated: 12/14/2025, 4:17:03 PM
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            ans[i]= nums[nums[i]];
        }
        return ans;
    }
};