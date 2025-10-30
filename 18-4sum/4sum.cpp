// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size(); //size of the array
//         vector<vector<int>> ans;

//         // sort the given array:
//         sort(nums.begin(), nums.end());

//         //calculating the quadruplets:
//         for (int i = 0; i < n; i++) {
//             // avoid the duplicates while moving i:
//             if (i > 0 && nums[i] == nums[i - 1]) continue;
//             for (int j = i + 1; j < n; j++) {
//                 // avoid the duplicates while moving j:
//                 if (j > i + 1 && nums[j] == nums[j - 1]) continue;

//                 // 2 pointers:
//                 int k = j + 1;
//                 int l = n - 1;
//                 while (k < l) {
//                     long long sum = nums[i];
//                     sum += nums[j];
//                     sum += nums[k];
//                     sum += nums[l];
//                     if (sum == target) {
//                         vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
//                         ans.push_back(temp);
//                         k++; l--;

//                         //skip the duplicates:
//                         while (k < l && nums[k] == nums[k - 1]) k++;
//                         while (k < l && nums[l] == nums[l + 1]) l--;
//                     }
//                     else if (sum < target) k++;
//                     else l--;
//                 }
//             }
//         }

//         return ans;
//         }
// };







class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicate j

                long long newTarget = (long long)target - nums[i] - nums[j]; // avoid overflow
                int left = j + 1, right = n - 1;

                while (left < right) {
                    long long sum = nums[left] + nums[right];

                    if (sum == newTarget) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // skip duplicates for left and right
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                    else if (sum < newTarget) {
                        left++;
                    } 
                    else {
                        right--;
                    }
                }
            }
        }

        return res;
    }
};


