class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count =0;
        int maxOne =0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]==0){
                count =0;
            }else{
                 count++;
                 maxOne = max(maxOne , count);
            }
           

            
        }
        return maxOne;
    }
};