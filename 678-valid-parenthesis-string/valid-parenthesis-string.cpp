class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;      // treat '*' as ')'
                high++;     // treat '*' as '('
            }

            // if even maximum is negative → invalid
            if (high < 0) return false;

            // low cannot be negative
            if (low < 0) low = 0;
        }

        // valid if we can end with 0 open brackets
        return low == 0;
    }
};