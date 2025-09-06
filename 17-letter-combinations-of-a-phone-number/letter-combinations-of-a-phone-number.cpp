class Solution {
public:
    void backtrack(int ind, string &path ,string &digits,vector<string> &ans, unordered_map<char, string> &mp){
        if(ind == digits.size()){
            ans.push_back(path);
            return;
        }

        string letters = mp[digits[ind]];
        for(char ch : letters){
            path.push_back(ch);
            backtrack(ind+1 , path, digits, ans, mp);
            path.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }

        // hash table 
        unordered_map<char, string> mp ={
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"},
            {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
            {'8',"tuv"},{'9',"wxyz"}
        };

        string path="";
        backtrack(0,path, digits, ans, mp);
        return ans;
    }
};