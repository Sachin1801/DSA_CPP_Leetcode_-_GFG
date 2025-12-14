// Last updated: 12/14/2025, 4:15:35 PM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans =0;
        for(auto x: nums){
            if(x%3==0) continue;
            else if(((x-1) % 3==0) || ((x+1) %3==0 )) ans ++;
        }
        return ans ;
    }
};