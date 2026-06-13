class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int left = 0;
        int count = 0;
        long long sum = 0;

        for(int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            while((long long)nums[right] *
                  (right - left + 1) - sum > k) {

                sum -= nums[left];
                left++;
            }

            count = max(count, right - left + 1);
        }

        return count;
    }
};