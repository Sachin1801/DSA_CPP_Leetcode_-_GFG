class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixsum(n,0);
        for(int i=0;i<n;i++){
            if(i==0) prefixsum[i]=nums[i];
            else prefixsum[i]= prefixsum[i-1]+nums[i];
        }

        unordered_map<int,int> m;
        queue<int> q;
        int i=0,j=0;
        while(j<k){
            m[nums[j]]++;
            j++;
        }
        long long ans = 0;
        if(m.size()==k){
            ans = max(ans,prefixsum[j-1]);
        }
        while(j<n){
            m[nums[i]]--;
            if(m[nums[i]]==0) m.erase(nums[i]);
            i++;
            m[nums[j]]++;
            if(m.size()==k){
                ans = max(ans,prefixsum[j]-prefixsum[i-1]);
            } 
            j++;
        }
        return ans;
    }
};