class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m1(nums1.begin(),nums1.end());
        unordered_set<int> m2(nums2.begin(),nums2.end());

        vector<int> diff1,diff2;
        for(int num: m1){
            if(m2.find(num)==m2.end())
                diff1.push_back(num);
        }
        for(int num: m2){
            if(m1.find(num)==m1.end())
                diff2.push_back(num);
        }
        return {diff1,diff2};
    }
};