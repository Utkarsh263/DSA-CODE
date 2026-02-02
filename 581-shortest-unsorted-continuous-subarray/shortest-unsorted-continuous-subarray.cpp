class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left =0, right = n-1;
        // Find the leftmost boundary 

        while(left < n-1 && nums[left] <= nums[left+1]){
            left++;
        }

        if(left== n-1){
            return 0;
        }

        // Find the rightmost boundary 

        while(right > 0 && nums[right] >= nums[right-1]){
            right--;
        }

        int subMin = INT_MAX;
        int subMax = INT_MIN;

        for(int i=left ; i<= right; i++){
            subMin = min(subMin, nums[i]);
            subMax = max(subMax, nums[i]);
        }

        while(left > 0 && nums[left-1] > subMin){
            left--;
        }

        while(right <n-1 && nums[right+1] < subMax){
            right++;
        }

        return right-left+1;
    }
};