// Last updated: 12/14/2025, 4:15:17 PM
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int max_diff=INT_MIN;
        for(int i =0 ;i< n;i++){
            int curr_diff = abs((nums[i]-nums[(i+1)%n]));
            max_diff = max(max_diff,curr_diff);
        }
        return max_diff;
    }
};