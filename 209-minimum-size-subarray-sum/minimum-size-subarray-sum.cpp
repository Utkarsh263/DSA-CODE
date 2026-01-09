class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int currSum = 0;
        int length = INT_MAX;
        

        for(int right = 0; right<n; right++){
            currSum += nums[right];
            while(currSum >= target){
                length = min(length, right-left+1);
                
                currSum -= nums[left];
                left++;
            }
            
        }

        return length == INT_MAX?0 : length;
    }
};