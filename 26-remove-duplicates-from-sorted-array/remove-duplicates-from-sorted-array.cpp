class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // Take two pointer i and j , one for iterating over the array and other for condition check and place it 

        int i=0;
        int n = nums.size();

        for(int j=0; j<n; j++){

            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }

        return i+1;
    }
};