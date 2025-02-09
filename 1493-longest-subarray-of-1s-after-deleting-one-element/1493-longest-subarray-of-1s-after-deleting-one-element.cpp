class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zcnt=0;
        int ans = 0 ;
        int i=0,j=0;
        int n = nums.size();
        while(j<n){
            if(nums[j]==0)zcnt++;
            if(zcnt>1){
                ans = max(ans,j-i-1);
                while(zcnt > 1){
                    if(nums[i]==0) zcnt--;
                    i++;
                }
            }
            j++;
        }
        ans = max(ans,j-i-1);
        return ans;
    }
};