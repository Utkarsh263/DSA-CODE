class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Sliding window approach 
        int count =0;
        int left = 0;
        long long product = 1;
        int n = nums.size();

        if(k<=1){
            return 0;
        }

        for(int right = 0; right<n; right++){

            product *= nums[right];

            while(product >= k){
                product = product / nums[left];
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
};