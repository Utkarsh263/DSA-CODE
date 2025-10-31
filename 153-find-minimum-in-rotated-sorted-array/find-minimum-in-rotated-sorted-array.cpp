class Solution {
public:
    int findMin(vector<int>& nums) {
        int left =0;
        int right = nums.size()-1;

        if(nums[left] < nums[right]){
            return nums[left];
        }

        while(left < right){
            int mid = (left+right)/2;

            // if mid element > right element 
            if(nums[mid] > nums[right]){
                left = mid+1;
            }else{
                right = mid;
            }
        }

        return nums[left];
    }
};







// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int low = 0;
//         int high = nums.size()-1;
//         int ans = INT_MAX;
//         int n = nums.size();

//         while(low <= high){
//             int mid = (low + high)/2;

//             if(nums[low]<=nums[mid]){
//                 ans = min(ans , nums[low]);
//                 low = mid+1;
//             }else{
//                 ans = min(ans , nums[mid]);
//                 high = mid-1;
//             }
//         }

//         return ans;
//     }
// };