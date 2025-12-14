// Last updated: 12/14/2025, 4:16:50 PM
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }
        
        for (const auto& [_, count] : counter) {
            if (count % 2 != 0) {
                return false;
            }
        }
        
        return true;
    }
}; 