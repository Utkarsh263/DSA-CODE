class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left =0;
        int right = nums.size()-1;

        while(left < right){
            int mid = (left + right)/2;

            // If mid is odd , make it even to make pair intact 
            if(mid %2 == 1){
                mid--;
            }

            if(nums[mid]==nums[mid+1]){
                left = mid+2;
            }else{
                right = mid;
            }
        }

        return nums[left];
    }
};