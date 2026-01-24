class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans(2, -1);

        // Find first occurence 
        int left =0;
        int right = n-1;

        while(left <= right){
            int mid = (left+right)/2;

            if(nums[mid] >= target){
                right = mid-1;
            }else{
                left = mid+1;
            }

            if(nums[mid]==target){
                ans[0] = mid;
            }
        }

        // Find last Occurence
        left =0;
        right = n-1;
        while(left <= right){
            int mid = (left+right)/2;

            if(nums[mid] <= target){
                left = mid+1;
            }else{
                right = mid-1;
            }

            if(nums[mid]==target){
                ans[1] = mid;
            }
        }
        return ans;
    }
};