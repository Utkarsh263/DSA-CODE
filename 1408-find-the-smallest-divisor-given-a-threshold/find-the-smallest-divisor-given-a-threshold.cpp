class Solution {
public:
    bool isValid(vector<int>&nums, int threshold , int divisor){
        long long sum = 0;
        for(int x : nums){
            sum += (x+divisor-1)/divisor;
            if(sum > threshold){
                return false;
            }
        }

        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while(low <= high){
            int mid = (low + high)/2;

            if(isValid(nums, threshold, mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};