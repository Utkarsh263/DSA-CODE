class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans = LLONG_MAX;

        multiset<int> small, large;
        long long sumSmall = 0;

        // Build initial window [1 ... dist+1]
        for (int i = 1; i <= dist + 1; i++) {
            small.insert(nums[i]);
            sumSmall += nums[i];

            if ((int)small.size() > k - 1) {
                auto it = prev(small.end());
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);
            }
        }

        ans = nums[0] + sumSmall;

        // Slide s1
        for (int s1 = 2; s1 + dist < n; s1++) {
            int out = nums[s1 - 1];
            int in = nums[s1 + dist];

            // Remove outgoing element
            if (small.find(out) != small.end()) {
                auto it = small.find(out);
                sumSmall -= *it;
                small.erase(it);

                if (!large.empty()) {
                    auto it2 = large.begin();
                    sumSmall += *it2;
                    small.insert(*it2);
                    large.erase(it2);
                }
            } else {
                large.erase(large.find(out));
            }

            // Insert incoming element
            small.insert(in);
            sumSmall += in;

            if ((int)small.size() > k - 1) {
                auto it = prev(small.end());
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);
            }

            ans = min(ans, nums[0] + sumSmall);
        }

        return ans;
    }
};
