class Solution {
public:
    bool canSplit(vector<int>&nums, int k , int maxSum){
        int subarrays = 1;
        long long currSum = 0;

        for(int num : nums){
            if(currSum + num > maxSum){
                subarrays++;
                currSum = num;

                if(subarrays > k){
                    return false;
                }
            }else{
                currSum += num;
            }
        }

        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for(int x : nums){
            high += x;
        }

        int ans = high;

        while(low <= high){
            int mid = (low+high)/2;

            if(canSplit(nums, k, mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};