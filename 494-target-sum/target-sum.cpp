class Solution {
public:
    int solve(int i, int sum , vector<int>&nums, vector<unordered_map<int, int>>&dp , int target){
        if(i==nums.size()){
            return sum == target ?1 : 0;
        }

        if(dp[i].count(sum)){
            return dp[i][sum];
        }

        int add = solve(i+1,sum+nums[i], nums, dp, target);
        int sub = solve(i+1, sum-nums[i], nums, dp, target);

        return dp[i][sum] = add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int , int>>dp(n); // dp[i][sums]=ways
        return solve(0, 0, nums, dp, target);
    }
};