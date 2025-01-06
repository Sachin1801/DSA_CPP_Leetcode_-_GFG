class Solution {

private:
    int numSubarrayWithSumlessthanequalto(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int csum = 0;
        int ans = 0;
        int l = 0, r = 0;
        while (r < nums.size()) {
            if(nums[r]&1)
                csum += 1;
            while (csum > goal) {
                if(nums[l++]&1)
                    csum -= 1;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return numSubarrayWithSumlessthanequalto(nums,k)-numSubarrayWithSumlessthanequalto(nums,k-1);
    }
};