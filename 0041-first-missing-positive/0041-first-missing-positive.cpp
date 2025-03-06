class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] < 1 || nums[i] > n)
                nums[i]=n+1;
        }
        for(int i=0;i<nums.size();i++){
            int num = abs(nums[i]);
            if(num <=n){
                int idx = num-1;
                if(nums[idx] > 0){
                    nums[idx] = -nums[idx];
                }
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0) return i+1;
        }
        return n+1;
    }
};