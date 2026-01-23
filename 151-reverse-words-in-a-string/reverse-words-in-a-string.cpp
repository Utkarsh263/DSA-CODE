class Solution {
public:
    string reverseWords(string s) {
        string word;
        stringstream ss(s);
        vector<string>words;

        while(ss >> word){
            words.push_back(word);
        }

        string result;

        for(int i = words.size()-1; i>= 0; i--){
            result += words[i];
            if(i > 0){
                result += " ";
            }
        }

        return result;
    }
};