class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(string s : strs) {

            vector<int> freq(26, 0);

            for(char ch : s) {
                freq[ch - 'a']++;
            }

            string key;

            for(int count : freq) {
                key += to_string(count) + "#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto& it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};