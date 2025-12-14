// Last updated: 12/14/2025, 4:17:13 PM
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        int maxPosSum = 0;
        int maxNegSum = 0;
        for(int i=0;i<n;i++){
            maxPosSum += nums[i];
            if(maxPosSum < 0) maxPosSum = 0;
            maxNegSum += nums[i];
            if(maxNegSum > 0) maxNegSum = 0;
            ans = max(ans,max(maxPosSum,abs(maxNegSum)));
        }

        return ans;
    }
};