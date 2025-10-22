class Solution {
public:
    int solve(int amount , vector<int> &coins , vector<int>&dp){
        if(amount==0){
            return 0;
        }
        if(dp[amount]!= -1){
            return dp[amount];
        }

        int res= INT_MAX;
        for(int coin : coins){
            if(amount-coin >=0){
                int sub = solve(amount-coin, coins , dp);
                if(sub != INT_MAX){
                    res= min(res, sub+1);
                }
            }
        }

        return dp[amount]= res;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, -1);
        int ans= solve(amount , coins ,dp);
        return ans==INT_MAX? -1 : ans;
    }
};