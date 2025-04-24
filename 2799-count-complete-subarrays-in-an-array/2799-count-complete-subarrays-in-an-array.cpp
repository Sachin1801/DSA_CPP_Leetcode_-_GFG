class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int left =0,right=0;
        int curr;
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        int tot_dist = freq.size();
        freq.clear();
        int ans = 0;
        while(right < n){
            freq[nums[right]]++;
            if(freq.size()==tot_dist){
                unordered_map<int,int> temp(freq.begin(),freq.end());
                curr = left;
                while(temp.size()==tot_dist){
                    ans++;
                    temp[nums[curr]]--;
                    if(temp[nums[curr]]==0) temp.erase(nums[curr]);
                    curr++;
                }
            }
            right++;
        }
        return ans;
    }
};