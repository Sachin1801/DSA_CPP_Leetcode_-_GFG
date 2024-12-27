class Solution {
    void find(int i,vector<int> &nums,vector<int> &curr,vector<vector<int>> &ans)
    {
        ans.push_back(curr);
        if(i==nums.size())
        return ;
        for(int idx=i;i<nums.size();i++)
        {
            curr.push_back(nums[i]);
            find(i+1,nums,curr,ans);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        find(0,nums,curr,ans);
        return ans;
    }
};