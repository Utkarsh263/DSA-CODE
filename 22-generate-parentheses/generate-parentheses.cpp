class Solution {
public:
    void solve(int n , int open , int close , string res , vector<string>&ans){

        if(res.size() == 2*n){
            ans.push_back(res);
            return;
        }

        // For opening bracket , max n can be used for opening 
        if(open < n){
            solve(n, open+1 , close , res+'(' , ans);
            
        }

        // Closing is dependent on opening bracets 
        if(close < open){
            solve(n, open , close+1 , res + ')', ans);
            
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr = "";

        solve(n, 0, 0, curr , ans);
        return ans;
    }
};