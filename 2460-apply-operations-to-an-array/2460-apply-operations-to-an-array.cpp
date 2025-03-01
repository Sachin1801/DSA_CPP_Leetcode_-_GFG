class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int zcnt =0;
        int j=0;
        while(j<2){
            int i=0;
            for(;i<n;i++){
                if(j==0){
                    if(i < n-1 && nums[i]==nums[i+1]){
                        nums[i] *=2;
                        nums[i+1]=0;
                    }
                }
                if(j==1){
                    if(nums[i]!=0) ans.push_back(nums[i]);
                    else zcnt++;
                }
            }
            j++;
        }
        while(zcnt--) ans.push_back(0);
        return ans;
    }
};