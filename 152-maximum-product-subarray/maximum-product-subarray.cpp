class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Here we have to track 2 numbers to track maximum and minimum  number 
        int maxEnd = nums[0];
        int minEnd = nums[0];
        int ans = nums[0];

        for(int i=1; i<nums.size(); i++){
            int curr = nums[i];

            int tempMax = max({curr, maxEnd*curr , curr*minEnd});
            int tempMin = min({curr, maxEnd*curr , minEnd*curr});

            maxEnd = tempMax;
            minEnd = tempMin;

            ans = max(ans, maxEnd);
        }

        return ans;
    }
};