class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxEnd = nums[0];
        int minEnd = nums[0];
        int ans = nums[0];

        int n = nums.size();

        for(int i=1; i<n; i++){
            int curr = nums[i];

            int tempMax = max({curr , curr*maxEnd , curr*minEnd});
            int tempMin = min({curr , curr*maxEnd, curr*minEnd});

            maxEnd = tempMax;
            minEnd = tempMin;

            ans = max(ans , maxEnd);
        }

        return ans;
    }
};