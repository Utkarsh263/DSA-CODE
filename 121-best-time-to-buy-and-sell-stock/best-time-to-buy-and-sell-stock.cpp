class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i=0; i<prices.size(); i++){
            
            minPrice = min(prices[i], minPrice);
            maxProfit = max(maxProfit , prices[i]-minPrice);
        }

        return maxProfit;
    }
};