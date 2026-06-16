// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {

//         if(nums.empty()) return 0;

//         sort(nums.begin(), nums.end());

//         int count = 1;
//         int ans = 1;

//         for(int i = 1; i < nums.size(); i++) {

//             if(nums[i] == nums[i - 1]) {
//                 continue; // skip duplicates
//             }
//             else if(nums[i] == nums[i - 1] + 1) {
//                 count++;
//             }
//             else {
//                 count = 1; // reset streak
//             }

//             ans = max(ans, count);
//         }

//         return ans;
//     }
// };



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int num : st) {

            // Start of a sequence
            if (st.find(num - 1) == st.end()) {

                int curr = num;
                int len = 1;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    len++;
                }

                longest = max(longest, len);
            }
        }

        return longest;
    }
};