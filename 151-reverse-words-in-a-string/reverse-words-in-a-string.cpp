class Solution {
public:
    string reverseWords(string s) {
        
        int i=0;
        int n = s.size();
        vector<string>words;  // Extra vector to store the words 

        while(i< n){
            //Leading spaces 
            while(i<n && s[i] == ' '){
                i++;
            }

            if(i>=n){
                break;
            }

            string word = "";
            while(i<n  && s[i] != ' '){
                word += s[i];
                i++;
            }

            words.push_back(word);
        }

        reverse(words.begin() , words.end());

        string result = "";
        for(int i=0; i<words.size();i++){
            result += words[i];

            if(i != words.size()-1){
                result += ' ';
            }
        }

        return result;
    }
};