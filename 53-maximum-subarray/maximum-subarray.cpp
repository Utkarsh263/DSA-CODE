class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int totalSum = INT_MIN;

        for(int i=0; i<nums.size(); i++){

            if(currSum < 0){
                currSum = 0;
            }
            currSum += nums[i];
            

            totalSum = max(totalSum , currSum);
        }

        return totalSum;
    }
};