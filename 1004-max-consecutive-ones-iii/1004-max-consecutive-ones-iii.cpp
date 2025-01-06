class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zerocnt=0;
        int i=0,j=0;
        int ans=0;
        while(j<nums.size()){
            if(nums[j]==0)
                zerocnt++;
            while(zerocnt > k){
                if(nums[i]==0)
                    zerocnt--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};