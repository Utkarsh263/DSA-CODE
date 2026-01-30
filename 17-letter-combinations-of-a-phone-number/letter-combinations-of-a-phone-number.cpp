class Solution {
public:
    void backtrack(int index, string &digits, vector<string>&mp, string &curr, vector<string>&ans){

        if(index == digits.size()){
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[index]-'0'];

        for(char ch : letters){
            curr.push_back(ch);
            backtrack(index+1, digits, mp, curr, ans);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string curr;

        vector<string> mp={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };

        backtrack(0, digits, mp, curr, ans);
        return ans;
    }
};