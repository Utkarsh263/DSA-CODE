class Solution {
public:
    int atMost(vector<int>&nums , int target){

        int left = 0;
        int count = 0;
        int n = nums.size();
        int sum = 0;

        if(target < 0){
            return 0;
        }

        for(int right = 0; right < n; right++){

            sum += nums[right];

            while(sum > target){

                sum -= nums[left];
                left++;
            }

            count += (right-left+1);
        }

        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return atMost(nums , goal) - atMost(nums , goal-1);
    }
};