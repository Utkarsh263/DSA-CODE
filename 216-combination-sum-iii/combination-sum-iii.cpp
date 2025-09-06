class Solution {
public:
    void backtrack(int start, int k , int n, vector<int> &ds , vector<vector<int>> &ans){
        if(ds.size()==k){
            if(n==0){
                ans.push_back(ds);
                
            }
            return;
        }

        for(int i=start; i<=9; i++){
            
            if(i> n){
                break;
            }
            ds.push_back(i);
            backtrack(i+1, k, n-i , ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        backtrack(1,k , n , ds, ans);
        return ans;
    }
};