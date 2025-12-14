// Last updated: 12/14/2025, 4:15:40 PM
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()<=1)
            return true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]&1 && nums[i+1]&1 )
                return false;
            else if(nums[i]%2==0 and nums[i+1]%2==0)
                return false;
        }
        return true;
    }
};