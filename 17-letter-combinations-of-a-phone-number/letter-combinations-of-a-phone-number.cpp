class Solution {
public:
    void backtrack(int index, string &path, string &digits, vector<string>&ans , unordered_map<char, string>&mp){
        if(index == digits.size()){
            ans.push_back(path);
            return;
        }

        string letters = mp[digits[index]];
        for(char ch : letters){
            path.push_back(ch);  // recursive add to the path
            backtrack(index+1, path, digits, ans, mp); // recursive call
            path.pop_back();  // backtrack the path
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }

        // mapping of digits to letters
        unordered_map<char, string>mp= {
             {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        string path = "";
        backtrack(0, path, digits, ans, mp);
        return ans;

    }
};