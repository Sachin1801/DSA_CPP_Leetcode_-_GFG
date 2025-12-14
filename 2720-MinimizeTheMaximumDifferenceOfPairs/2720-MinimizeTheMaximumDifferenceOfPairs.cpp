// Last updated: 12/14/2025, 4:15:54 PM
class Solution {
private:
    bool check(vector<int> &nums, int p, int diff, int n){
        int i =0;
        int curr =0;
        while(i<n-1){
            if(abs(nums[i]-nums[i+1]) <= diff){
                curr++;
                i+=2;
            }else{
                i++;
            }
            if(curr >=p) return true;
        }
        return false;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        int r = abs(nums[0] - nums[n-1]);

        int ans =r;
        while(l<=r){
            int mid= l + (r-l)/2 ;
            bool can_find_p_pair = false;
            can_find_p_pair = check(nums,p,mid,n);
            if(can_find_p_pair){
                ans = min(ans,mid);
                r = mid - 1; 
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};