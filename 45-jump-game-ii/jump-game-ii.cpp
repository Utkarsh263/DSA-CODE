class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;       // count of jumps
        int curEnd = 0;      // end of current jump range
        int farthest = 0;    // farthest we can reach so far
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            
            // when we reach end of current range, make a jump
            if (i == curEnd) {
                jumps++;
                curEnd = farthest;
            }
        }
        return jumps;
    }
};
