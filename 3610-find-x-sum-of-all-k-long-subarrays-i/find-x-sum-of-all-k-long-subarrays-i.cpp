class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> freq;

        // Sliding window [i, j]
        int i = 0;
        for (int j = 0; j < n; j++) {
            // Add nums[j] to window
            freq[nums[j]]++;

            // Shrink window if too big
            while (j - i + 1 > k) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0)
                    freq.erase(nums[i]);
                i++;
            }

            // If window has exactly k elements
            if (j - i + 1 == k) {
                // Extract all (value, freq) pairs
                vector<pair<int, int>> pairs;
                for (auto& p : freq)
                    pairs.push_back({p.first, p.second});

                // Sort by frequency descending, then by value descending
                sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
                    if (a.second != b.second)
                        return a.second > b.second;
                    return a.first > b.first;
                });

                // Compute X-Sum: sum of first x elements' (freq * val)
                int xSum = 0;
                for (int idx = 0; idx < x && idx < pairs.size(); idx++) {
                    xSum += pairs[idx].first * pairs[idx].second;
                }
                ans.push_back(xSum);
            }
        }

        return ans;
    }
};