// Last updated: 12/14/2025, 4:15:53 PM
class Solution {
public:
    static bool doesValidArrayExist(vector<int>& derived) {
        return accumulate(derived.begin(), derived.end(), 0, bit_xor<>())==0;
    }
};