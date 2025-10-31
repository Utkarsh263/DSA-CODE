// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if(strs.empty()){
//             return "";
//         }

//         for(int i=0; i<strs[0].size(); i++){
//             char ch = strs[0][i];

//             for(int j=1; j<strs.size(); j++){

//                 if(i >= strs[j].size() || strs[j][i] != ch){
//                     return strs[0].substr(0,i);
//                 }
//             }
//         }

//         return strs[0];
//     }
// };




class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0]; // take first string as the initial prefix

        for (int i = 1; i < strs.size(); i++) {
            // while current string doesn't start with prefix
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1); // cut last char
                if (prefix.empty()) return ""; // no common prefix
            }
        }

        return prefix;
    }
};