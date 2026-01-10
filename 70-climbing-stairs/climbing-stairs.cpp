class Solution {
public:
    int climbStairs(int n) {
        // To climb stairs n , we can find n-1 for 1 and n-2 as 2 stairs at a time 

        vector<int>dp(n+1, 0);

        dp[0] = 1; // its a way 
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};