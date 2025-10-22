class Solution {
public:
    bool solve(int i, int sum , vector<int>&nums, vector<vector<int>>&dp){
        if(sum ==0){
            return true;
        }

        if(i==0){
            return nums[0]==sum;  //only first element taken as target
        }

        if(dp[i][sum] !=-1){
            return dp[i][sum];
        }

        bool notTake = solve(i-1, sum , nums, dp);
        bool take = false;
        if(sum >= nums[i]){
            take = solve(i-1, sum-nums[i], nums, dp);
        }

        return dp[i][sum] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int x : nums){
            total += x;
        }
        if(total %2 != 0){
            return false;
        }
        int target = total/2;
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>(target+1, -1));

        return solve(n-1 , target , nums, dp);
    }
};