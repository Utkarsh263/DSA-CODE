class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Try for Time Complexity O(N)
        vector<int>ans(nums.size());

        int product = 1;
        int zeroes = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                zeroes++;
            }else{
                product *= nums[i];
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(zeroes > 1){

                nums[i] = 0;

            }else if(zeroes ==1){

                ans[i] = nums[i] == 0? product : 0;
            }else{

                ans[i] = product/nums[i];
            }

            
        }

        return ans;
    }
};