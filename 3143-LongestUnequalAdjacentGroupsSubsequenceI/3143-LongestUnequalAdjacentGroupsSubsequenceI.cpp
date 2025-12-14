// Last updated: 12/14/2025, 4:15:48 PM
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        int prev = -1; // initially nothing selected

        for (int i = 0; i < words.size(); ++i) {
            if (prev == -1 || groups[i] != prev) {
                result.push_back(words[i]);
                prev = groups[i];
            }
        }

        return result;
    }
};
