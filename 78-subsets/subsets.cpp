class Solution {
public:
    void backtrack(vector<int> &nums, int i ,vector<int> &subset , vector<vector<int>>&result){

        if(i == nums.size()){
            result.push_back(subset);
            return;
        }

        // Exclusion
        backtrack(nums, i+1 , subset , result);

        // Inclusion
        subset.push_back(nums[i]);
        backtrack(nums, i+1, subset , result);
        subset.pop_back(); //backtrack

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int> subset;
        backtrack(nums, 0, subset, result);
        return result;
    }
};