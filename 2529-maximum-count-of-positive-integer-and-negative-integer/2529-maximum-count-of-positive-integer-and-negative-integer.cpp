class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos_cnt=0,neg_cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0) neg_cnt++;
            else if(nums[i]>0) pos_cnt++;
        }
        return max(neg_cnt,pos_cnt);

    }
};