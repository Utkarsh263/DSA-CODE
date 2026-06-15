class Solution {
public:
    void solve(int idx, string &digits , string &path , vector<string>&result , vector<string>&phone){

        if(idx == digits.size()){
            result.push_back(path);
            return;
        }

        string letters = phone[digits[idx] - '0'];

        for(char ch : letters){
            path.push_back(ch);
            solve(idx+1 , digits , path , result , phone);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()){
            return {};
        }

        vector<string> phone = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        vector<string>result;
        string path;

        solve(0, digits, path, result , phone);

        return result;
    }
};