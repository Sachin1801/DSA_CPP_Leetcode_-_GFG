// Last updated: 12/14/2025, 4:15:15 PM
class Solution {
    static constexpr long long MOD = 1'000'000'007LL;

public:
    int countPartitions(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<long long> dp(n + 1, 0), pre(n + 1, 0);
        dp[0] = pre[0] = 1;

        deque<int> maxQ, minQ;   // store indices
        int l = 0;

        for (int r = 0; r < n; ++r) {
            // push nums[r] into monotone deques
            while (!maxQ.empty() && nums[maxQ.back()] <= nums[r]) maxQ.pop_back();
            while (!minQ.empty() && nums[minQ.back()] >= nums[r]) minQ.pop_back();
            maxQ.push_back(r);
            minQ.push_back(r);

            // shrink left edge until window is valid
            while (!maxQ.empty() && !minQ.empty()
                   && nums[maxQ.front()] - nums[minQ.front()] > k) {
                if (maxQ.front() == l) maxQ.pop_front();
                if (minQ.front() == l) minQ.pop_front();
                ++l;
            }

            // dp transition
            long long ways = (pre[r] - (l ? pre[l - 1] : 0) + MOD) % MOD;
            dp[r + 1] = ways;
            pre[r + 1] = (pre[r] + ways) % MOD;
        }
        return static_cast<int>(dp[n]);
    }
};