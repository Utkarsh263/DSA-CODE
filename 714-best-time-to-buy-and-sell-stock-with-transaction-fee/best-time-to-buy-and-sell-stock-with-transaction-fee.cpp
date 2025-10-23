class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;

        int hold = -prices[0];  // holding stock on day 0
        int notHold = 0;        // not holding stock on day 0

        for (int i = 1; i < n; i++) {
            hold = max(hold, notHold - prices[i]);           // buy or hold
            notHold = max(notHold, hold + prices[i] - fee);  // sell or skip
        }
        return notHold;
    }
};
