class Solution {
public:
    vector<int> ans;

    void merge(vector<pair<int,int>>& a, int l, int m, int r) {
        vector<pair<int,int>> temp;
        int i = l, j = m + 1;

        while (i <= m && j <= r) {
            if (a[i].first <= a[j].first) {
                temp.push_back(a[j++]);
            } else {
                ans[a[i].second] += (r - j + 1);
                temp.push_back(a[i++]);
            }
        }

        while (i <= m) temp.push_back(a[i++]);
        while (j <= r) temp.push_back(a[j++]);

        for (int k = l; k <= r; k++) {
            a[k] = temp[k - l];
        }
    }

    void mergeSort(vector<pair<int,int>>& a, int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.assign(n, 0);

        vector<pair<int,int>> a;
        for (int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        mergeSort(a, 0, n - 1);
        return ans;
    }
};
