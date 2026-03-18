class Solution {
public:
    string reverseWords(string s) {
        
        string word;
        stringstream ss(s);
        vector<string>words;

        while(ss>>word){
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string result = "";
        for(string w : words){
            result += w+" ";
        }

        result.pop_back();

        return result;
    }
};