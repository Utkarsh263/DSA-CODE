class Solution {
public:
    void backtrack(int index, vector<int>&candidates, vector<int>&path , int target , vector<vector<int>>&ans){

        if(target == 0){
            ans.push_back(path);
            return;
        }

        if(target < 0 || index == candidates.size()){
            return;
        }

        // Include the number 
        path.push_back(candidates[index]);
        backtrack(index, candidates, path , target-candidates[index], ans);
        path.pop_back();

        // Exclude the number 
        backtrack(index+1, candidates, path, target, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>path;
        vector<vector<int>>ans;
        backtrack(0, candidates, path , target, ans);
        return ans;
    }
};