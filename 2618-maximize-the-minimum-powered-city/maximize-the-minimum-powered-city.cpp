#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, long long k) {
        int n = stations.size();
        // prefix sums to compute initial power for each city
        vector<long long> pref(n+1, 0);
        for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + stations[i];

        // initial power at city i = sum of stations in [max(0,i-r) .. min(n-1,i+r)]
        vector<long long> power(n);
        for (int i = 0; i < n; ++i) {
            int L = max(0, i - r);
            int R = min(n - 1, i + r);
            power[i] = pref[R+1] - pref[L];
        }

        long long totalStations = pref[n];
        long long low = 0;
        long long high = totalStations + k; // upper bound: all stations (existing + added) at one city

        while (low < high) {
            long long mid = (low + high + 1) / 2;
            if (canAchieve(power, r, k, mid)) low = mid;
            else high = mid - 1;
        }
        return low;
    }

private:
    // Check if we can make every city's power >= target using at most k extra stations
    bool canAchieve(const vector<long long>& power, int r, long long k, long long target) {
        int n = power.size();
        vector<long long> diff(n + 1, 0); // diff trick to apply range adds efficiently
        long long used = 0;   // total extra stations used
        long long addSum = 0; // current accumulated added stations effect at position i

        int windowSpan = 2 * r + 1;
        for (int i = 0; i < n; ++i) {
            addSum += diff[i];                 // apply any scheduled removal at i
            long long current = power[i] + addSum;
            if (current < target) {
                long long need = target - current;
                used += need;
                if (used > k) return false;
                addSum += need;
                int endPos = i + windowSpan;  // end index (exclusive) where this addition stops
                if (endPos <= n) diff[endPos] -= need;
                // if endPos > n, it goes beyond array so no diff write needed (we used diff size n+1)
            }
        }
        return true;
    }
};
