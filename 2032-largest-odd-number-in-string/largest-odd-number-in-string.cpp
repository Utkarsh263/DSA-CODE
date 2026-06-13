class Solution {
public:
    string largestOddNumber(string nums) {
        
        // We have to find largest odd number in the string 
        for(int i=nums.size()-1 ; i>=0; i--){
            if(nums[i] % 2 == 1){
                return nums.substr(0, i+1);  // Its 0 based indexing 
            }
        }

        return "";
    }
};