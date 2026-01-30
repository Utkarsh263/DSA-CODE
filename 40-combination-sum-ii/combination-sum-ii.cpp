class Solution {
public:
    void backtrack(int index, vector<int>&candidates, int target, vector<int>&path, vector<vector<int>>&ans){

        if(target == 0){
            ans.push_back(path);
            return;
        }

        for(int i=index; i<candidates.size(); i++){

            if(i > index && candidates[i]==candidates[i-1]){
                continue;
            }

            if(target < candidates[i]){
                break;
            }

            path.push_back(candidates[i]);
            backtrack(i+1, candidates, target-candidates[i], path, ans);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>path;
        vector<vector<int>>ans;
        backtrack(0, candidates, target, path, ans);
        return ans;
    }
};