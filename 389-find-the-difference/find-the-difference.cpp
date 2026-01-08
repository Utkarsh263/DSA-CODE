class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;

        for(char c : s){
            ans = ans ^ c;
        }

        for(char c : t){
            ans = ans ^ c;
        }

        return ans;
    }
};

// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         vector<int>freq(26, 0);

//         for(int i=0; i<t.size(); i++){
//             freq[t[i]-'a']++;
//         }

//         for(int i=0; i<s.size();i++){
//             freq[s[i]-'a']--;
//         }

//         for(int i=0; i<26; i++){
//             if(freq[i] > 0){
//                 return char(i + 'a');
//             }
//         }

//         return 'a';
//     }
// };