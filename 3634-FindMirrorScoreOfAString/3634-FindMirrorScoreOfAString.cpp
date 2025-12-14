// Last updated: 12/14/2025, 4:15:27 PM
class Solution {
public:
    long long calculateScore(string s) {
        // Create a mirror mapping for each lowercase letter
        std::unordered_map<char, char> mirrorMap;
        for (char c = 'a'; c <= 'z'; ++c) {
            mirrorMap[c] = 'z' - (c - 'a');
        }

        long long score = 0;
        std::unordered_map<char, std::vector<int>> unmarkedIndices;

        for (size_t i = 0; i < s.length(); ++i) {
            char mirrorChar = mirrorMap[s[i]];
            if (!unmarkedIndices[mirrorChar].empty()) {
                int j = unmarkedIndices[mirrorChar].back();
                unmarkedIndices[mirrorChar].pop_back();
                score += (i - j);
            } else {
                unmarkedIndices[s[i]].push_back(i);
            }
        }

        return score;
    }
};