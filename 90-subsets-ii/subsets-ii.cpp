class Solution {
public:
    void backtrack(int start, vector<int>&nums, vector<int>&path , vector<vector<int>>&result){
        result.push_back(path);

        for(int i=start; i<nums.size(); i++){
            if(i >start && nums[i-1]== nums[i]){
                continue;
            }

            path.push_back(nums[i]);
            backtrack(i+1, nums, path, result);
            path.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, path, result);
        return result;
    }
};