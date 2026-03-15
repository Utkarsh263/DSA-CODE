class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int minPrice = prices[0];

        for(int num : prices){
            minPrice = min(minPrice , num);
            maxProfit = max(maxProfit , num-minPrice);
        }

        return maxProfit;
    }
};