class Solution {

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        int n = nums.size();
        int limit = pow(2,n) - 1;
        for(int num = 0; num <=limit; num++){
            vector<int> substring;
            for(int i=0;i<n;i++){
                if(num&(1<<i))
                    substring.push_back(nums[i]);
            }
            ans.push_back(substring);
        }
        return ans;
    }
};