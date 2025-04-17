class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> idxList;
        int ans =0;
        for(int i=0;i<nums.size();i++){
            if(idxList[nums[i]].size()!=0){
                for(auto num: idxList[nums[i]]){
                    if((i*num)%k==0) ans++;
                }
            }
            idxList[nums[i]].push_back(i);
        }    
        return ans;
    }
};