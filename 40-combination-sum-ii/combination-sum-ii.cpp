class Solution {
public:
    void solve(int idx, vector<int>&candidates , int target , vector<int>&path , vector<vector<int>>&result){

       if(target == 0){
            result.push_back(path);
            return;
       }

       for(int i=idx; i<candidates.size(); i++){
        
            // Skip duplicates
            if(i> idx && candidates[i] == candidates[i-1]){
                continue;
            }

            if(candidates[i] > target){
                break;
            }

            path.push_back(candidates[i]);
            solve(i+1 , candidates , target-candidates[i] , path , result);
            path.pop_back();
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>path;
        vector<vector<int>>result;
        sort(candidates.begin(), candidates.end());

        solve(0, candidates , target , path, result);

        return result;
    }
};