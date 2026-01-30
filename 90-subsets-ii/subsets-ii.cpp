class Solution {
public:
    void backtrack(int index, vector<int>&nums, vector<int>&path, vector<vector<int>>&ans){
        ans.push_back(path);

        for(int i=index; i<nums.size(); i++){

            if(i>index && nums[i]==nums[i-1]){
                continue;
            }

            // Include in subset
            path.push_back(nums[i]);
            backtrack(i+1, nums, path, ans);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>path;
        vector<vector<int>>ans;
        backtrack(0,nums, path, ans);
        return ans;
    }
};