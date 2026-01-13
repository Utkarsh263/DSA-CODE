class Solution {
public:
    vector<vector<int>>result;
    vector<int>path;

    void backtrack(vector<int>&candidates, int target, int start){

        // base case
        if(target==0){
            result.push_back(path);
            return;
        }

        for(int i=start; i<candidates.size(); i++){

            if(candidates[i]> target){
                return;
            }

            path.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Sort the array for pruning 
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);

        return result;
    }
};