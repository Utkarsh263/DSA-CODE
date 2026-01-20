class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int x : nums) {
            int best = -1;

            // Try all possible a < x
            for (int a = 0; a < x; a++) {
                if ( (a | (a + 1)) == x ) {
                    best = a;
                    break;  // smallest a found
                }
            }

            ans.push_back(best);
        }
        return ans;
    }
};
