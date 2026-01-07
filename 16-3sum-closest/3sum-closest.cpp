class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort the array and then use the two pointer approach 

        sort(nums.begin(), nums.end());
        int n = nums.size();

        int closestSum = nums[0]+nums[1]+nums[2];
        int minDiff = abs(target - closestSum);

        for(int i=0; i<n-2; i++){
            int left = i+1;
            int right = n-1;

            while(left < right){
                int sum = nums[i] + nums[left]+ nums[right];
                int diff = abs(target - sum);

                if(diff < minDiff){
                    minDiff = diff;
                    closestSum = sum;
                }

                if(sum< target){
                    left++; // as larger value is needed
                }else if(sum > target){
                    right--;
                }else{
                    return sum;
                }
            }
        }

        return closestSum;
    }
};