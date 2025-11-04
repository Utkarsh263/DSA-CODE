class Solution {
public:
    void backtrack(vector<int>& digits, vector<bool>& used, vector<int>& path, unordered_set<int>& result) {
        if (path.size() == 3) {
            int num = path[0]*100 + path[1]*10 + path[2];
            if (path[0] != 0 && path[2] % 2 == 0) {
                result.insert(num);
            }
            return;
        }

        for (int i = 0; i < digits.size(); i++) {
            if (used[i]) continue;
            
            // \U0001f6ab Skip duplicate digits at same recursion level
            if (i > 0 && digits[i] == digits[i - 1] && !used[i - 1])
                continue;

            used[i] = true;
            path.push_back(digits[i]);

            backtrack(digits, used, path, result);

            path.pop_back();
            used[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) {
        unordered_set<int> result;
        vector<bool> used(digits.size(), false);
        vector<int> path;

        sort(digits.begin(), digits.end()); // ✅ helps skip duplicates efficiently

        backtrack(digits, used, path, result);

        return result.size();
    }
};
