class Solution {
    private: 
    void compute(int i, vector<int> &nums, vector<int> &current, set<vector<int>> &s ){
        if(i==nums.size()){
            s.insert(current);
            return;
        }

        //recursion
        //step 1: ignore the current integer
        compute(i+1,nums,current,s);

        //step2: include the current int
        current.push_back(nums[i]);
        compute(i+1,nums,current,s);
        current.pop_back();
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> current;
        sort(nums.begin(),nums.end());
        compute(0,nums,current,s);
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};