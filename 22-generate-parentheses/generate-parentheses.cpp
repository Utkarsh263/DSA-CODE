class Solution {
public:
    void backtrack(int n , int open , int end, string curr, vector<string>&result){
        if(curr.size()==2*n){
            result.push_back(curr);
            return;
        }

        // condition for opening character

        if(open < n){
            backtrack(n , open+1, end , curr+ '(' , result);
        }

        // condition for closing character

        if(end < open){
            backtrack(n , open , end+1, curr+')' , result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n , 0, 0, "", result);
        return result;
    }
};