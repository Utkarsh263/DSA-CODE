class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;
        int res = 0;

        for (auto &word : words) {
            dp[word] = 1;  // Minimum chain length is 1
            for (int i = 0; i < word.size(); i++) {
                string pred = word.substr(0, i) + word.substr(i+1); // remove i-th char
                if (dp.find(pred) != dp.end()) {
                    dp[word] = max(dp[word], dp[pred] + 1);
                }
            }
            res = max(res, dp[word]);
        }

        return res;
    }
};
