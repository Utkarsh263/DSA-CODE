class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        // Sort the string array 
        sort(strs.begin(), strs.end());

        string front = strs.front();
        string back = strs.back();

        int i = 0;
        while(i<front.size() && i<back.size() && front[i] == back[i]){
            i++;
        }

        return front.substr(0, i);
    }
};