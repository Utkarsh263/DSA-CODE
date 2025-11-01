class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long low = 0, high = 0;
        for (int x : nums) {
            low = max<long long>(low, x);
            high += x;
        }

        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (canSplit(nums, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return static_cast<int>(low);
    }

private:
    bool canSplit(const vector<int>& nums, int k, long long maxAllowed) {
        int needed = 1;         // start with 1 subarray
        long long sum = 0;
        for (int x : nums) {
            if (sum + x > maxAllowed) {
                // must start a new subarray
                needed++;
                sum = x;
                if (needed > k) {
                    return false;
                }
            } else {
                sum += x;
            }
        }
        return true;
    }
};












// class Solution {
// public:
// int helper(vector<int>nums,int mid){
//   int count=1;
//   int sum=0;
//   for(int i=0;i<nums.size();i++){
//         if(sum+nums[i]<=mid){
//             sum=sum+nums[i];
//         }
//         else{
//             count++;
//             sum=nums[i];
//         }
//   }
//   return count;
// }
//     int splitArray(vector<int>& nums, int k) {
//         int low=*max_element(nums.begin(),nums.end()),high,mid;
//         for(int i=0;i<nums.size();i++){
//             high+=nums[i];
//         }
//         while(low<=high){
//             mid=(low+high)/2;
//             int res=helper(nums,mid);
//             if(res>k){
//               low=mid+1;
//             }else{
//                     high=mid-1;
//             }
//         }
//         return low;
        
//     }
// };