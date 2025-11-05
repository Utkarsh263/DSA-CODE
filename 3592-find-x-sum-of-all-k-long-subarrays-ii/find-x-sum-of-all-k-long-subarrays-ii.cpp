class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int,int> freq;

        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b){
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };

        set<pair<int,int>, decltype(cmp)> topX(cmp), rest(cmp);
        long long currSum = 0;
        vector<long long> ans;

        auto rebalance = [&]() {
            // Promote best from rest while topX.size() < x
            while ((int)topX.size() < x && !rest.empty()) {
                auto it = rest.begin();
                topX.insert(*it);
                currSum += 1LL * it->first * it->second;
                rest.erase(it);
            }
            // If best in rest is better than worst in topX, swap them
            while (!rest.empty() && !topX.empty()) {
                auto bestRest = rest.begin();              // best candidate in rest
                auto worstTop = prev(topX.end());         // worst in topX
                // if bestRest > worstTop (by cmp), move it
                if (cmp(*bestRest, *worstTop)) {
                    // move bestRest -> topX
                    currSum += 1LL * bestRest->first * bestRest->second;
                    topX.insert(*bestRest);
                    rest.erase(bestRest);
                    // move worstTop -> rest
                    currSum -= 1LL * worstTop->first * worstTop->second;
                    rest.insert(*worstTop);
                    topX.erase(worstTop);
                } else break;
            }
        };

        auto erasePair = [&](const pair<int,int>& p) {
            auto itTop = topX.find(p);
            if (itTop != topX.end()) {
                currSum -= 1LL * p.first * p.second;
                topX.erase(itTop);
            } else {
                auto itRest = rest.find(p);
                if (itRest != rest.end()) rest.erase(itRest);
            }
        };

        // insert into rest first; rebalance will promote if needed
        auto insertPairToRest = [&](const pair<int,int>& p) {
            rest.insert(p);
        };

        auto insertNum = [&](int val) {
            int f = ++freq[val];
            pair<int,int> now = {f, val};
            pair<int,int> prevPair = {f - 1, val};
            if (f > 1) erasePair(prevPair);
            insertPairToRest(now);
            rebalance();
        };

        auto removeNum = [&](int val) {
            int f = freq[val];
            pair<int,int> now = {f, val};
            erasePair(now);
            f--;
            if (f == 0) freq.erase(val);
            else {
                freq[val] = f;
                pair<int,int> updated = {f, val};
                insertPairToRest(updated);
            }
            rebalance();
        };

        for (int i = 0; i < n; ++i) {
            insertNum(nums[i]);
            if (i >= k) removeNum(nums[i - k]);
            if (i >= k - 1) ans.push_back(currSum);
        }

        return ans;
    }
};
