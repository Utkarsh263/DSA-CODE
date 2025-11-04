class Solution {
public:
    void backtrack(int start, int k , int n , vector<int>&path, vector<vector<int>>&result){
        if(path.size()==k && n==0){
            result.push_back(path);
            return;
        }

        if(path.size() > k || n <0){
            return;
        }

        for(int i=start; i<=9; i++){
            path.push_back(i);
            backtrack(i+1,k, n-i,path, result);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>path;
        vector<vector<int>>result;
        backtrack(1, k , n , path, result);
        return result;
    }
};