class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int left = 0, right = 0;

        while (right < n - 1) {
            int right_max = nums[right]+right;
            while (left < right) {
                right_max = max(nums[left] + left, right_max);
                left++;
            }
            left = right + 1;
            right = right_max;
            jumps++;
        }
        return jumps;
    }
};