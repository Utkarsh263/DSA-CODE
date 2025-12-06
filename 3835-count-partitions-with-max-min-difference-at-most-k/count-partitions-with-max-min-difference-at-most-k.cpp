class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const long long MOD = 1'000'000'007;
        int n = nums.size();

        // dp[i] = number of ways for first i elements
        vector<long long> dp(n + 1, 0);
        vector<long long> pref(n + 1, 0);  // prefix sums of dp

        dp[0] = 1;
        pref[0] = 1;

        deque<int> dqMax, dqMin;
        int l = 0;

        for (int i = 0; i < n; i++) {

            // Maintain max deque (non-increasing)
            while (!dqMax.empty() && nums[dqMax.back()] <= nums[i])
                dqMax.pop_back();
            dqMax.push_back(i);

            // Maintain min deque (non-decreasing)
            while (!dqMin.empty() && nums[dqMin.back()] >= nums[i])
                dqMin.pop_back();
            dqMin.push_back(i);

            // Shrink left boundary until window satisfies max - min ≤ k
            while (!dqMax.empty() && !dqMin.empty() &&
                   nums[dqMax.front()] - nums[dqMin.front()] > k) {

                if (dqMax.front() == l) dqMax.pop_front();
                if (dqMin.front() == l) dqMin.pop_front();
                l++;
            }

            // dp[i+1] = sum(dp[l] .. dp[i])
            long long sum = pref[i];
            if (l > 0) {
                sum = (sum - pref[l - 1]) % MOD;
                if (sum < 0) sum += MOD;
            }

            dp[i + 1] = sum;
            pref[i + 1] = (pref[i] + dp[i + 1]) % MOD;
        }

        return dp[n];
    }
};
