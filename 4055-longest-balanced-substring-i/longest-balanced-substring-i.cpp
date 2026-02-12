class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            unordered_map<int, int> countFreq;

            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';

                int oldFreq = freq[idx];
                int newFreq = oldFreq + 1;
                freq[idx] = newFreq;

                // remove old frequency
                if (oldFreq > 0) {
                    countFreq[oldFreq]--;
                    if (countFreq[oldFreq] == 0)
                        countFreq.erase(oldFreq);
                }

                // add new frequency
                countFreq[newFreq]++;

                // balanced if only one frequency exists
                if (countFreq.size() == 1) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};