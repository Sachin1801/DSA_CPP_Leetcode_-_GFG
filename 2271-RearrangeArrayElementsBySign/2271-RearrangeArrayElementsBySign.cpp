// Last updated: 12/14/2025, 4:16:52 PM
class Solution {
public:

    void next_pos(int &i, vector<int>& nums){
        while(i < nums.size() and nums[i]<0){
            i++;
        }
        return;
    }

    void next_neg(int &j, vector<int>& nums){
        while(j< nums.size() and nums[j]>0){
            j++;
        }
        return;
    }

    vector<int> rearrangeArray(vector<int>& nums) {
        int i=0,j=0;
        next_pos(i,nums);
        next_neg(j,nums);
        
        vector<int> ans;
        while(i< nums.size() and j<nums.size()){
            ans.push_back(nums[i++]);
            next_pos(i,nums);
            ans.push_back(nums[j++]);
            next_neg(j,nums);
        }
        return ans;
    }
};