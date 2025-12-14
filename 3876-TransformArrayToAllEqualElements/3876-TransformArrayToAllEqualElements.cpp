// Last updated: 12/14/2025, 4:15:10 PM
class Solution {
private:
    bool canConvert(vector<int> nums, int k, int tar){
        int wrong = 0;
        for(auto x: nums){
            if(x!=tar) wrong++;
        }
        if(wrong%2!=0) return false;

        int ops = 0;
        int n = nums.size();
        for(int i =0; i< n-1; i++){
            if(nums[i]!=tar){
                nums[i] *= -1;
                nums[i+1] *= -1;
                if(++ops > k ) return false;
            }
        }
        return nums[n-1]==tar;
    }
    
public:
    bool canMakeEqual(vector<int>& nums, int k) {

        return canConvert(nums,k,1) || canConvert(nums,k,-1);
        
    }
};