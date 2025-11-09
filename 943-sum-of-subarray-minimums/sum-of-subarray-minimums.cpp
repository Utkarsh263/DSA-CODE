class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<pair<int,int>> st1, st2;
        const int MOD = 1e9 + 7;

        // Step 1: Previous Less Element (PLE)
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (!st1.empty() && st1.top().first > arr[i]) {
                count += st1.top().second;
                st1.pop();
            }
            st1.push({arr[i], count});
            left[i] = count;
        }

        // Step 2: Next Less or Equal Element (NLE)
        for (int i = n - 1; i >= 0; i--) {
            int count = 1;
            while (!st2.empty() && st2.top().first >= arr[i]) {
                count += st2.top().second;
                st2.pop();
            }
            st2.push({arr[i], count});
            right[i] = count;
        }

        // Step 3: Contribution of each element
        long long result = 0;
        for (int i = 0; i < n; i++) {
            result = (result + (long long)arr[i] * left[i] * right[i]) % MOD;
        }

        return result;
    }
};
