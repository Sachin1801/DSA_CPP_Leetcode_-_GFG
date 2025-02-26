class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> posSum(n,0);
        vector<int> negSum(n,0);
        int maxPosSum = 0;
        int maxNegSum = 0;
        for(int i=0;i<n;i++){
            maxPosSum += nums[i];
            if(maxPosSum < 0) maxPosSum = 0;
            posSum.push_back(maxPosSum);
            maxNegSum += nums[i];
            if(maxNegSum > 0) maxNegSum = 0;
            negSum.push_back(abs(maxNegSum));
        }
        auto posMax = max_element(posSum.begin(),posSum.end());
        auto negMax = max_element(negSum.begin(),negSum.end());

        return max(*posMax, *negMax);
    }
};