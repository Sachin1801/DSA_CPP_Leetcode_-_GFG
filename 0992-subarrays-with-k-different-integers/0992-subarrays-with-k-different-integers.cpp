class Solution {

private:
    int valid_parts(vector<int>&nums, int k){
        int i=0,j=0;
        int cnt =0;
        unordered_map<int,int> m;
        while(j<nums.size()){
            m[nums[j]]++;
            while(m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]]==0)
                    m.erase(nums[i]);
                i++;
            }
            if(m.size()<=k)
                cnt+= j-i+1;
            j++;
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return valid_parts(nums,k) - valid_parts(nums,k-1);
    }
};