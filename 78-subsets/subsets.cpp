class Solution {
public:
    void solve(int idx, vector<int>&nums , vector<int>&path , vector<vector<int>>&result){

        if(idx == nums.size()){
            result.push_back(path);
            return;
        }

        // Include it 
        path.push_back(nums[idx]);
        solve(idx+1 , nums , path , result);
        path.pop_back();

        //Exclude it 
        solve(idx+1 , nums , path , result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>result;
        vector<int>path;

        solve(0, nums , path , result);

        return result;
    }
};