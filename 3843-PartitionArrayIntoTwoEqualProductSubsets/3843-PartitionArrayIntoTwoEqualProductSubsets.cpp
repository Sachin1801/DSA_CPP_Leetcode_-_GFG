// Last updated: 12/14/2025, 4:15:14 PM
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        /* -------- 1. basic impossible cases -------- */
        if (target == 1) return false;                  // distinct ↔ only one ‘1’ exists
        const int n = nums.size();
        if (n < 2) return false;

        /* -------- 2. compute total product safely -------- */
        __int128 totProd = 1;                           // 128-bit
        for (int v : nums) totProd *= v;

        __int128 need = (__int128)target * (__int128)target;
        if (totProd != need) return false;              // necessary condition

        /* -------- 3. scan all proper, non-empty subsets --------
           n ≤ 12 ⇒ 2^n ≤ 4096, dirt-cheap                            */
        int fullMask = 1 << n;                          // bitmask over 12 items
        for (int mask = 1; mask < fullMask - 1; ++mask) {
            __int128 prod = 1;
            for (int i = 0; i < n && prod <= target; ++i) {
                if (mask & (1 << i)) prod *= nums[i];
            }
            if (prod == target) return true;            // complement auto-matches
        }
        return false;
    }
};
