class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0,right=0;
        int n = nums.size();
        int ans = INT_MAX;
        int csum=0;
        while(right< n){
            csum+= nums[right];
            while(left <= right && csum >=target){
                ans = min(ans,right-left+1);
                csum -= nums[left++];
            }
            right++;
        }
        return ans==INT_MAX ? 0 : ans;
    }
};