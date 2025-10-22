#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int target = total_sum / 2;

        // Function to generate all subset sums for a half
        auto getSubSums = [&](vector<int>& arr) {
            int sz = arr.size();
            vector<vector<int>> sums(sz + 1); // sums[count] = list of subset sums with count elements
            for(int mask = 0; mask < (1 << sz); mask++) {
                int sum = 0, count = 0;
                for(int i = 0; i < sz; i++) {
                    if(mask & (1 << i)) {
                        sum += arr[i];
                        count++;
                    }
                }
                sums[count].push_back(sum);
            }
            return sums;
        };

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        auto left_sums = getSubSums(left);
        auto right_sums = getSubSums(right);

        // Sort sums for binary search
        for(int i = 0; i <= n; i++) {
            sort(left_sums[i].begin(), left_sums[i].end());
            sort(right_sums[i].begin(), right_sums[i].end());
        }

        int ans = INT_MAX;

        // Combine left and right subsets
        for(int k = 0; k <= n; k++) { // number of elements taken from left
            if(left_sums[k].empty() || right_sums[n - k].empty()) continue;

            for(int ls : left_sums[k]) {
                auto& rs_list = right_sums[n - k];

                // Binary search closest sum in right list
                auto it = lower_bound(rs_list.begin(), rs_list.end(), target - ls);

                if(it != rs_list.end())
                    ans = min(ans, abs(total_sum - 2 * (ls + *it)));
                if(it != rs_list.begin()) {
                    --it;
                    ans = min(ans, abs(total_sum - 2 * (ls + *it)));
                }
            }
        }

        return ans;
    }
};
