class Solution {
public:
    int maximizeSquareArea(int m, int n,
                           vector<int>& hFences,
                           vector<int>& vFences) {

        const long long MOD = 1e9 + 7;

        // Add boundary fences (cannot be removed)
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> horizontalDistances;

        // All possible horizontal distances
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                horizontalDistances.insert(hFences[j] - hFences[i]);
            }
        }

        int maxSide = 0;

        // All possible vertical distances
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int width = vFences[j] - vFences[i];
                if (horizontalDistances.count(width)) {
                    maxSide = max(maxSide, width);
                }
            }
        }

        if (maxSide == 0) return -1;

        return (maxSide * 1LL * maxSide) % MOD;
    }
};
