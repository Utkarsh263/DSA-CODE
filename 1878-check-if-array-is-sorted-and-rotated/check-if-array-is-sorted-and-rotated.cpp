class Solution {
public:
    bool check(vector<int>& nums) {
        
        // If array is sorted and rotated so there will only be one point where sorted order breaks 

        int n = nums.size();
        int count = 0;

        for(int i=1; i<n; i++){

            if(nums[i] < nums[i-1]){
                count++;
            }
        }
        // To check condition for the last element of the array 
        if(nums[n-1] > nums[0]){
            count++;
        }

        return count<=1;
    }
};