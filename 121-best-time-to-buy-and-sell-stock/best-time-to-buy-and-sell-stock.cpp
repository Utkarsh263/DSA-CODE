class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // As take a min price and try to sell on every day with min price so far to gain max profit 

        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i=1; i<prices.size(); i++){

            minPrice = min(minPrice , prices[i]);
            int profit = prices[i]-minPrice;

            maxProfit = max(maxProfit , profit);
        }

        return maxProfit;
    }
};