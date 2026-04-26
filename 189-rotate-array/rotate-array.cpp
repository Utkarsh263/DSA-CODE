class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k % n;

        // Reverse the whole array 
        reverse(nums.begin(), nums.end());

        // Reverse the first half
        reverse(nums.begin(), nums.begin()+k);

        // Reverse the rest half
        reverse(nums.begin()+k , nums.end());

    }
};