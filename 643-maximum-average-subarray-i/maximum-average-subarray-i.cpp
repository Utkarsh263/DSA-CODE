class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum =0;
        double maxSum = -1e18;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];

            if(i >= k-1){
                maxSum = max(maxSum, sum);
                sum -= nums[i-k+1];
            }
        }

        return maxSum/k;
    }
};