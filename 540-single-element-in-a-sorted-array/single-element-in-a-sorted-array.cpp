class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left =0;
        int right = nums.size()-1;
        while(left < right){
            int mid = (left + right)/2;

            // checking for the pairs 
            if(mid %2 ==1){// first elemt of pair so mid--
                mid--;
            }

            if(nums[mid] == nums[mid+1]){
                left = mid+2;
            }else{
                right = mid;
            }
        }

        return nums[left];
    }
};







// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& arr) {
//         int n = arr.size();
//         if(n==1){
//             return  arr[0];
//         }
//         if(arr[0] != arr[1]){
//             return arr[0];    
//         }
//         if(arr[n-1] != arr[n-2]){
//             return arr[n-1];
//         }

//         int low =1;
//         int high = n-2;

//         while(low <= high){
//             int mid = (low + high)/2;

//             if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]){
//                 return arr[mid];
//             }

//             if((mid % 2 == 1 && arr[mid] == arr[mid-1]) || (mid %2 ==0 && arr[mid] == arr[mid+1])){
//                 low = mid+1;
//             }else{
//                 high = mid-1;
//             }
//         }

//         return -1;

//     }
// };