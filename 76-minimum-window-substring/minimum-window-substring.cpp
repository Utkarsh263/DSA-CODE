class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> need;   // count of chars required
        unordered_map<char, int> window; // count of chars in current window

        // Build frequency map of string t
        for (char c : t) {
            need[c]++;
        }

        int have = 0;                    // how many chars satisfy condition
        int needCount = need.size();     // unique characters required
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {
            char c = s[right];
            window[c]++;

            // If current char satisfies the requirement
            if (need.count(c) && window[c] == need[c]) {
                have++;
            }

            // Contract window while valid
            while (have == needCount) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Pop from left
                char leftChar = s[left];
                window[leftChar]--;
                if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                    have--;
                }
                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
