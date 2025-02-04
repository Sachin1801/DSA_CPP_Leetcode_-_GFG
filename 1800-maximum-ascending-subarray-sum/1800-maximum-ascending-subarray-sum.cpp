class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        int msum=0;
        int csum=0;
        int n = nums.size();
        int i ;
        for(i=0;i<n-1;i++){
            while(i<n-1 and nums[i]<nums[i+1]){
                csum+=nums[i];
                i++;
            }
            csum += nums[i];
            if(csum > msum )
                msum = csum;
            csum=0;
        }
        return msum;
    }
};