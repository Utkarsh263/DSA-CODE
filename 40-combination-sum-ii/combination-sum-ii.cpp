class Solution {
public:
    void backtrack(int ind , vector<int> &candidates , int target , vector<int> &ds , vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }

        for(int i=ind ; i<candidates.size(); i++){
            if(i> ind && candidates[i-1]== candidates[i]){
                continue;
            }
            if(candidates[i] > target){
                break; // pruning
            }
            //target = target- candidates[i];
            ds.push_back(candidates[i]);
            backtrack(i+1, candidates, target- candidates[i] , ds , ans);
            ds.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        backtrack(0, candidates, target, ds, ans);
        return ans;
    }
};