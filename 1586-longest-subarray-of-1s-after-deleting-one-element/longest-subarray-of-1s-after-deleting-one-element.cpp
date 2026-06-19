class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int left = 0;
        int n = nums.size();
        int zeroCount = 0;
        int res = 0;

        for(int right=0; right<n; right++){

            if(nums[right] == 0){
                zeroCount++;
            }

            while(zeroCount > 1){

                if(nums[left] == 0){
                    zeroCount--;
                }

                left++;
            }

            res = max(res , right-left);
        }

        return res;
    }
};