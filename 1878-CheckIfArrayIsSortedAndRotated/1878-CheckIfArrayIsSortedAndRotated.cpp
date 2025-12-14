// Last updated: 12/14/2025, 4:17:12 PM
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            if(nums[i] > nums[(i+1)%n])
                cnt++;
            
        }
        return cnt<=1? true: false;
    }
};