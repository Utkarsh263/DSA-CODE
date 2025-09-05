class Solution {
public:
    void backtrack(vector<int> &nums, int i, vector<int> &subset , vector<vector<int>> &result){
        if(i== nums.size()){
            result.push_back(subset);
            return;
        }

        // exclusion case
        backtrack(nums, i+1, subset, result);
        // inclusion case
        subset.push_back(nums[i]);
        backtrack(nums, i+1, subset, result);
        subset.pop_back(); // Jacket example to put off older one to try newer one 
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>subset;
        backtrack(nums,0,subset, result);
        return result;
    }
};