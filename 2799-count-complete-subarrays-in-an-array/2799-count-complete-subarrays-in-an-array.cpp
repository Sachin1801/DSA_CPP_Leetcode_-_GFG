class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int l =0, r=0, n= nums.size(), ans =0;
        bitset<2001> ht;
        bitset<2001> curr;
        for(int i=0;i<n;i++){
            if(!ht.test(nums[i])) ht.set(nums[i]);
        }
        vector<int> ht2(2001,0);
        while(r<n){
            curr.set(nums[r]);
            ht2[nums[r]]++;
            while(curr == ht && l <= r){
                ans += (n-r);

                ht2[nums[l]]--;
                if(ht2[nums[l]]==0) curr.reset(nums[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};