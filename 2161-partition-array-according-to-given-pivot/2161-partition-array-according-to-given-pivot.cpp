class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        unordered_map<char,vector<int>> m;
        m.reserve(3);
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]< pivot)
                m['l'].push_back(nums[i]);
            else if(nums[i]==pivot)
                m['e'].push_back(nums[i]);
            else
                m['g'].push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            for(int elem: m['l']){
                nums[i++] = elem;
            }
            for(auto elem: m['e']){
                nums[i++] = elem;
            }
            for(auto elem: m['g']){
                nums[i++] = elem;
            }
        }
        return nums;
    }
};