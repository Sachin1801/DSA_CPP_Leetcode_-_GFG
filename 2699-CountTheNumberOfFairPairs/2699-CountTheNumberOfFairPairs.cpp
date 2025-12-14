// Last updated: 12/14/2025, 4:15:56 PM
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans =0 ;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            int low = lower-nums[i];
            int high = upper - nums[i];
            auto l = lower_bound(nums.begin()+i+1, nums.end(),low);
            auto r = upper_bound(nums.begin()+i+1, nums.end(),high);
            ans += r-l;
        }
        return ans;
    }
};