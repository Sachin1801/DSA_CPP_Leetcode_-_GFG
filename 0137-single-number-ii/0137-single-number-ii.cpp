class Solution {
public:
    // int singleNumber(vector<int>& nums) {
    //     int ans =0;
    //     for(int i=0;i<=31;i++){
    //         int cnt= 0;
    //         for(int j=0;j<nums.size();j++){
    //             if(nums[j]&(1<<i))
    //                 cnt++;
    //             if(cnt%3==1)
    //                 ans = ans | (1<<i);
    //         }
    //     }
    //     return ans;
    // }

    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i=0;i<nums.size();i++){
            ones = (ones^nums[i]) & ~(twos);
            twos = (twos^nums[i]) & ~(ones);
        }
        return ones;
    }
};