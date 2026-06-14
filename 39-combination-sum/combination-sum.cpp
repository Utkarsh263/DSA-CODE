class Solution {
public:
    void solve(int idx , vector<int>&candidates , int target , vector<int>&path , vector<vector<int>>&result){

        if(idx == candidates.size()){
            if(target == 0){
                result.push_back(path);
            }
            return;
        }

        // Excluded 
        solve(idx+1, candidates , target , path , result);

        if(target >= candidates[idx]){
            path.push_back(candidates[idx]);
            target = target - candidates[idx];
            solve(idx , candidates , target , path , result);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>path;

        solve(0, candidates , target , path , result);
        return result;
    }
};