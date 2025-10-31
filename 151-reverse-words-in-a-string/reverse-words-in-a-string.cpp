class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        while(ss >> word){
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string result = "";
        for(int i=0; i<words.size(); i++){
            result += words[i];

            if(i !=words.size()-1){
                result += " ";
            }
        }

        return result;
    }
};




// class Solution {
// public:
//     string reverseWords(string s) {
//         // 1. Remove extra spaces
//         int n = s.size();
//         int i = 0, j = 0;

//         while (j < n) {
//             // skip leading spaces
//             while (j < n && s[j] == ' ') j++;
//             if (j >= n) break;

//             // add space before next word (not before first)
//             if (i > 0) s[i++] = ' ';

//             // copy word
//             int start = j;
//             while (j < n && s[j] != ' ') s[i++] = s[j++];

//             // reverse the word in-place
//             reverse(s.begin() + start, s.begin() + i);
//         }

//         // remove trailing
//         s.resize(i);

//         // 2. Reverse the entire string
//         reverse(s.begin(), s.end());

//         return s;
//     }
// };
