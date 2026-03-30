class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int left =0;
        int ans = 0;
        int zeroCount =0;

        for(int right =0; right < nums.size(); right++){

            // Increment the zero count 
            if(nums[right]==0){
                zeroCount++;
            }

            // If window becomes invalid , keep removing characters from the window's left 

            while(zeroCount > k){
                if(nums[left]==0){

                    zeroCount--;
                }
                left++;
            }

            // update the ans variable 
            ans = max(ans , right-left+1); 

        }

        return ans;
    }
};