// class Solution {
// public:
//     vector<int> seg;
//     int m;

//     void update(int idx, int l, int r, int pos) {
//         if (l == r) {
//             seg[idx]++;
//             return;
//         }
//         int mid = (l + r) / 2;
//         if (pos <= mid) update(2*idx, l, mid, pos);
//         else update(2*idx+1, mid+1, r, pos);
//         seg[idx] = seg[2*idx] + seg[2*idx+1];
//     }

//     int query(int idx, int l, int r, int ql, int qr) {
//         if (qr < l || ql > r) return 0;
//         if (ql <= l && r <= qr) return seg[idx];
//         int mid = (l + r) / 2;
//         return query(2*idx, l, mid, ql, qr) + query(2*idx+1, mid+1, r, ql, qr);
//     }

//     int reversePairs(vector<int>& nums) {
//         int n = nums.size();
//         vector<long long> vals;
//         for (int x : nums) {
//             vals.push_back(x);
//             vals.push_back(2LL * x);
//         }
//         sort(vals.begin(), vals.end());
//         vals.erase(unique(vals.begin(), vals.end()), vals.end());

//         auto getId = [&](long long x) {
//             return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
//         };

//         m = vals.size();
//         seg.assign(4 * (m + 2), 0);

//         long long res = 0;
//         for (int i = n - 1; i >= 0; i--) {
//             int id = getId(nums[i]) - 1;
//             res += query(1, 1, m, 1, id);
//             update(1, 1, m, getId(2LL * nums[i]));
//         }

//         return (int)res;
//     }
// };











class Solution {
public:
    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;
        
        int mid = (low + high) / 2;
        int count = mergeSort(nums, low, mid) + mergeSort(nums, mid + 1, high);

        // Count reverse pairs
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j])
                j++;
            count += (j - (mid + 1));
        }

        // Merge two sorted halves
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);
        }
        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        for (int i = low; i <= high; i++)
            nums[i] = temp[i - low];

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
