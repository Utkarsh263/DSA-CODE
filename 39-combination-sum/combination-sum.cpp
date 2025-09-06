class Solution {
public:
    void backtrack(int i ,vector<int>& candidates, int target,vector<int>&ds , vector<vector<int>>&result){
        if(i== candidates.size()){
            if(target == 0){
                result.push_back(ds);
            }
            return;
        }

        // Exclusion case 
        backtrack(i+1,candidates,target,ds, result);

        // Inclusion case
        if(candidates[i] <= target){
            target = target - candidates[i];
            ds.push_back(candidates[i]);
            backtrack(i,candidates, target, ds, result);
            ds.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> result;
       vector<int> ds;
       backtrack(0, candidates, target, ds, result);
       return result; 
    }
};