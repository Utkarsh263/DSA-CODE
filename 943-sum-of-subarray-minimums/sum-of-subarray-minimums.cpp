class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> left(n), right(n);
        stack<int> st;

        // 1️⃣ Find left distances (previous smaller element)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty())
                left[i] = i + 1;
            else
                left[i] = i - st.top();

            st.push(i);
        }

        // Clear stack for reuse
        while (!st.empty()) st.pop();

        // 2️⃣ Find right distances (next smaller or equal element)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n - i;
            else
                right[i] = st.top() - i;

            st.push(i);
        }

        // 3️⃣ Calculate total contribution
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long contribution =
                (long long)arr[i] * left[i] * right[i];
            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};
