class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        k = k % nums.size();
        // First reverse the whole array 
        reverse(nums.begin(), nums.end());

        // Reverse upto k
        reverse(nums.begin(), nums.begin()+k);

        // Reverse the left 
        reverse(nums.begin()+k , nums.end());
    }
};