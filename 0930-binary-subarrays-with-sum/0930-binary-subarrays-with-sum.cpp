class Solution {

private:
    int numSubarrayWithSumlessthanequalto(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int csum = 0;
        int ans = 0;
        int l = 0, r = 0;
        while (r < nums.size()) {
            csum += nums[r];
            while (csum > goal) {
                csum -= nums[l++];
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarrayWithSumlessthanequalto(nums, goal) -
               numSubarrayWithSumlessthanequalto(nums, goal - 1);
    }
};