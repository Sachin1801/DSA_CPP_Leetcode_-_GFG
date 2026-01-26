class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        //corner case 
        if(k==1) return 0;

        sort(nums.begin(),nums.end());
        int n = nums.size();

        if(k==n){
            return nums[n-1]-nums[0];
        }
        int i = 0, j = k-1;

        int minDiff = INT_MAX;
        while(i < n - k +1 ){
            minDiff = min(minDiff, (nums[j]-nums[i]));
            i++,j++;
        }
        return minDiff;

    }
};