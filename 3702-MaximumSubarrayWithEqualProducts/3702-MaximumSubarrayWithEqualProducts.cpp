// Last updated: 12/14/2025, 4:15:22 PM

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;

        // Helper function to calculate GCD of two numbers
        auto gcd = [](long long a, long long b) {
            while (b != 0) {
                long long temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        };

        // Helper function to calculate LCM of two numbers safely
        auto lcm = [&](long long a, long long b) {
            return (a / gcd(a, b)) * b;
        };

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long curr_gcd = nums[i];
            long long curr_lcm = nums[i];

            for (int j = i; j < n; ++j) {
                prod *= nums[j];

                // Check for overflow when updating product
                if (prod > 1e12) break;

                curr_gcd = gcd(curr_gcd, nums[j]);
                curr_lcm = lcm(curr_lcm, nums[j]);

                if (prod == curr_gcd * curr_lcm) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }

        return max_len;
    }
};