#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: Exclude last house
        int case1 = robLinear(nums, 0, n - 2);
        // Case 2: Exclude first house
        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }

private:
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int i = start; i <= end; i++) {
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
