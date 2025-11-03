class Solution {
public:
    void backtrack(vector<string>&res, string &curr, int open , int close, int n){
        if((int)curr.size()== 2*n){
            res.push_back(curr);
        }

        // Try adding  '(' bracket
        if(open < n){
            curr.push_back('(');
            backtrack(res , curr, open+1, close, n);
            curr.pop_back();  // backtrack
        }

        if(close < open){
            curr.push_back(')');
            backtrack(res, curr, open , close+1, n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        backtrack(res, curr, 0, 0, n);
        return res;
    }
};