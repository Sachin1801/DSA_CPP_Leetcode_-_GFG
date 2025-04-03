class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxi = INT_MIN, diff =0, n = nums.size();
        long long res = 0;

        for(int i=0;i<n;i++){
            maxi = max(nums[i],maxi); // update the maximum value seen so far
            if(i>=2)
                res = max(res,(long long)diff*nums[i]); // computing the maximum triplet
            if(i>=1)
                diff = max(diff, maxi-nums[i]); //update the maxa difference
        }
        return res;
    }
};