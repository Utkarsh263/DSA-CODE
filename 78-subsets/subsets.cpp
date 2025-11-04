class Solution {
public:
    void backtrack(int i , vector<int>&nums, vector<int>&path, vector<vector<int>>&result){
        if(i==nums.size()){
            result.push_back(path);
            return;
        }

        // Excluding the item 
        backtrack(i+1, nums, path, result);
        // Including the item
        path.push_back(nums[i]);
        backtrack(i+1, nums, path, result);
        path.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>path;
        vector<vector<int>>result;
        backtrack(0,nums, path, result);
        return result;
    }
};