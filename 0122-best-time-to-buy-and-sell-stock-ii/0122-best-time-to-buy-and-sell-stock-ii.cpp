class Solution {

public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1)
            return 0;

        int n = prices.size();
        vector<int> ahead(2,0), curr(2,0);

        ahead[0] = ahead[1] = 0;
        int profit;
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy < 2; buy++) {
                if (buy) {
                    profit =
                        max(-prices[idx] + ahead[0],
                            0 + ahead[1]);
                } else {
                    profit = max(prices[idx] + ahead[1],
                                 0 + ahead[0]);
                }
                curr[buy]=profit;
            }
            ahead = curr;
        }
        return curr[1];
    }
};