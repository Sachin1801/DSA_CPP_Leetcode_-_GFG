class Solution {
public:

    bool test(vector<int> &nums, int divisor, int threshold){
        int sum = 0;
        for(auto x : nums){
            sum += ceil(double(x) / double(divisor));
            if(sum > threshold)
                return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxele = *max_element(nums.begin(),nums.end());
        int low = 1;
        int ans = maxele;
        while(low<=maxele){
            int mid = (low+maxele) / 2;
            if(test(nums,mid,threshold)){
                ans = min(ans,mid);
                maxele = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};