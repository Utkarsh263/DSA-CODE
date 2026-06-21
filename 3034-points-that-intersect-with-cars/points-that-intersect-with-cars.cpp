class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> freq(101, 0);
        int n = nums.size();
        int start, end;
        for (int i = 0; i < n; i++) {
            start = nums[i][0];
            end = nums[i][1];
            while (start <= end) {
                freq[start] = 1;
                start++;
            }
        }
        int count = 0;
        for (int i = 1; i < 101; i++)
            if (freq[i] != 0)
                count++;

        return count;
    }
};