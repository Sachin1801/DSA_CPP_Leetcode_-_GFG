class Solution {
private:
    int ans =0;

    void solve(vector<int> &nums, int i, int currxor){
        if(i>=nums.size()){
            ans += currxor;
            return;
        }

        //option 1: not pick
        solve(nums,i+1,currxor);

        //option 2: pick
        solve(nums,i+1,currxor^nums[i]);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        solve(nums,0,0);
        return ans;
    }
};