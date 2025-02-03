class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        int inc=1;
        int dec =1;
        int n = nums.size();
        int ans = 1;
        for(int i=0;i<n-1;i++){
            while(i<n-1 && nums[i]<nums[i+1]){
                inc++;
                i++;
            }
            while(i<n-1 && nums[i] > nums[i+1]){
                dec++;
                i++;
            }
            if(i < n-1 && nums[i] < nums[i+1])
                i--;
            
            if(inc > ans || dec > ans)
                ans = max(inc,dec);
            inc = 1;
            dec= 1;
        }
        return ans;
    }
};