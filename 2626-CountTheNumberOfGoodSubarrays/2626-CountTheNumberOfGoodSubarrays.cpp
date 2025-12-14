// Last updated: 12/14/2025, 4:16:02 PM
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        unordered_map<int,int>freq;
        long long pairCnt = 0, goodSubarray = 0;
        int left= 0;
        for(int right = 0 ; right < nums.size(); right++){
            pairCnt += freq[nums[right]];
            freq[nums[right]]++;

            while(pairCnt >= k){
                goodSubarray += nums.size()-right;
                freq[nums[left]]--;
                pairCnt -= freq[nums[left]];
                left++;
            }
        }
        return goodSubarray;
    }
};