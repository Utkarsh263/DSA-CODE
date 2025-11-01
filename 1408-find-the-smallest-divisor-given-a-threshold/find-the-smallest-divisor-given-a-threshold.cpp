class Solution {
public:
    int sumAfterDivision(vector<int> &nums, int divisor){
        int total=0;
        for(int n : nums){
            total += (n+divisor-1)/divisor;
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1;
        int high = *max_element(nums.begin(), nums.end());

        while(low < high){
            int mid = (low + high)/2;
            if(sumAfterDivision(nums, mid) > threshold){
                low = mid+1;
            }else{
                high = mid;
            }
        }

        return low;
    }
};






// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int maximum (vector<int> &nums){
//         int maxi = INT_MIN;
//         for(int i=0; i<nums.size(); i++){
//             maxi = max(nums[i], maxi);
//         }

//         return maxi;
//     }

//     int sumbyD(vector<int> &nums, int d){
//         int n = nums.size();
//         int sum = 0;
//         for(int i=0; i<n ; i++){
//             sum += ceil((double)nums[i]/(double)d);
//         }
//         return sum;
//     }

//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int low =1;
//         int high = maximum(nums);
//         while(low <= high){
//             int mid = (low+high)/2;

//             if(sumbyD(nums,mid) <= threshold){
//                 high = mid-1;
//             }else{
//                 low = mid+1;
//             }
//         }

//         return low;

//     }
// };