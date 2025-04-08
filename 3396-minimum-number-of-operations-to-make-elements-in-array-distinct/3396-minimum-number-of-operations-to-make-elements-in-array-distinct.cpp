class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        deque<int> dq(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            int cnt = 0;
            if (freq[nums[i]] > 1) {
                while (freq[nums[i]] > 1 && !dq.empty()) {
                    int val = dq.front();
                    dq.pop_front();
                    freq[val]--;
                    cnt++;
                }

                while (cnt % 3 != 0 && !dq.empty()) {
                    int val = dq.front();
                    dq.pop_front();
                    freq[val]--;
                    cnt++;
                }
                if(cnt%3==0) ans += cnt/3;
                else ans += (cnt / 3)+1;
            }
        }
        return ans;
    }
};