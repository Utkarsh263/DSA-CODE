class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // sort greed factors
        sort(s.begin(), s.end()); // sort cookie sizes

        int i = 0; // index for children
        int j = 0; // index for cookies

        // loop until either all children checked OR all cookies used
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // cookie j can satisfy child i
                i++; // move to next child
            }
            // either way, we used cookie j
            j++;
        }
        return i; // number of satisfied children
    }
};
