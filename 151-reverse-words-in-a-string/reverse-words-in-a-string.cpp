class Solution {
public:
    string reverseWords(string s) {
        
        string word;
        vector<string>words;
        stringstream ss(s);

        while(ss >> word){
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string result = "";
        for(string w : words){
            result += w+ " ";
        }

        result.pop_back();

        return result;
    }
};