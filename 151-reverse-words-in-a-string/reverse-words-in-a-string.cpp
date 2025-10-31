// class Solution {
// public:
//     string reverseWords(string s) {
//         stringstream ss(s);
//         string word;
//         vector<string> words;

//         while(ss >> word){
//             words.push_back(word);
//         }

//         reverse(words.begin(), words.end());

//         string result = "";
//         for(int i=0; i<words.size(); i++){
//             result += words[i];

//             if(i !=words.size()-1){
//                 result += " ";
//             }
//         }

//         return result;
//     }
// };




class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        // Step 1: Remove extra spaces (in-place)
        int i = 0, j = 0;

        while (j < n) {
            // Skip leading spaces
            while (j < n && s[j] == ' ') j++;
            if (j >= n) break;

            // Add a single space before next word (except before first)
            if (i > 0) s[i++] = ' ';

            // Copy the next word
            int start = i;
            while (j < n && s[j] != ' ') {
                s[i++] = s[j++];
            }

            // Reverse the current word in place
            reverse(s.begin() + start, s.begin() + i);
        }

        // Resize to remove trailing spaces
        s.resize(i);

        // Step 2: Reverse the entire cleaned string
        reverse(s.begin(), s.end());

        return s;
    }
};

