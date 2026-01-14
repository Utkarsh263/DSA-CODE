class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int minVal = nums[0];
        for(int n : nums){
            minVal = min(minVal, n);
        }

        int minMoves=0;
        for(int n : nums){
            minMoves += (n-minVal);
        }

        return minMoves;
    }
};