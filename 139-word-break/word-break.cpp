// class Solution {
// public:
//     bool backtrack(int start, string &s, unordered_set<string>&dict){
//         if(start == s.size()){
//             return true;
//         }

//         for(int end = start+1; end <= s.size(); end++){
//             string word = s.substr(start, end-start);
//             if(dict.count(word)){
//                 if(backtrack(end, s, dict)){
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.begin(), wordDict.end());
//         return backtrack(0, s, dict);
//     }
// };





class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);  // -1 = not visited
        
        return canBreak(0, s, dict, memo);
    }

private:
    bool canBreak(int start, string &s, unordered_set<string> &dict, vector<int> &memo) {
        // Base case: reached end successfully
        if (start == s.size()) return true;
        
        // If already computed
        if (memo[start] != -1) return memo[start];
        
        // Try all possible splits
        for (int end = start + 1; end <= s.size(); ++end) {
            string word = s.substr(start, end - start);
            if (dict.count(word) && canBreak(end, s, dict, memo)) {
                return memo[start] = 1;  // store result & return true
            }
        }
        return memo[start] = 0;  // store result & return false
    }
};
