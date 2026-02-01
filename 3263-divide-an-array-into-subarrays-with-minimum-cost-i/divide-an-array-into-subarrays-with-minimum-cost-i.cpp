class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = nums[0];

        int smallest = INT_MAX;
        int sec_smallest = INT_MAX;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] < smallest){
                sec_smallest = smallest;
                smallest = nums[i];
            }else if(nums[i] < sec_smallest){
                sec_smallest = nums[i];
            }
        }
        return smallest + first+ sec_smallest;
    }
};