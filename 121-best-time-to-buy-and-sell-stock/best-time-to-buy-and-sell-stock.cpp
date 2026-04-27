class Solution {
public:
    int maxProfit(vector<int>& nums) {
        
        int n = nums.size();
        int minPrice = nums[0];
        int maxProfit = 0;

        for(int i=1; i<n; i++){

            minPrice = min(minPrice ,nums[i]);
            maxProfit = max(maxProfit , nums[i]-minPrice);
        }

        return maxProfit;
    }
};