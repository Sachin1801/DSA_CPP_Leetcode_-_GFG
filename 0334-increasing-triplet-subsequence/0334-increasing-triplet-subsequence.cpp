class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()< 3) return false;
        int n = nums.size();
        int s1=INT_MAX, s2 = INT_MAX, s3 = INT_MAX;
        for(int i=0;i<n-2;i++){
            if(nums[i]<s1){
                s1 = nums[i];
                for(int j=i+1;j<n-1;j++){
                    if(nums[j]< s2 && nums[j] > s1){
                        s2 = nums[j];
                        for(int k=j+1;k<n;k++){
                            if(nums[k] > s1 && nums[k]> s2 )
                                return true;
                        }
                    }
                }
                s2= INT_MAX;
            }
        }
        return false;
    }
};