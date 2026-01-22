class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMax=0, maxSum = nums[0];
        int currMin =0, minSum = nums[0];

        for(int x : nums){

            // Kadane for MaxSum 
            currMax = max(x, currMax+x);
            maxSum = max(currMax , maxSum);

            // Kadane for minSum 
            currMin = min(x, currMin+x);
            minSum = min(currMin , minSum);
        }

        return max(maxSum , abs(minSum));
    }
};