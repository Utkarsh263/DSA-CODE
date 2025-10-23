// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<long long>>dp(n+1, vector<long long>(amount+1,0));
//         for(int i=0; i<n+1; i++){
//             dp[i][0] = 1;
//         }
//         for(int i=1;i<n+1; i++){
//             for(int j=1; j<amount+1; j++){
//                 if(coins[i-1]<=j){
//                     dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
//                 }else{
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }

//         return dp[n][amount];

//     }
// };


// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         // use long long for DP counts
//         vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1, 0LL));

//         for (int i = 0; i <= n; ++i) dp[i][0] = 1LL;

//         for (int i = 1; i <= n; ++i) {
//             for (int j = 1; j <= amount; ++j) {
//                 // exclude current coin
//                 dp[i][j] = dp[i - 1][j];
//                 // include current coin
//                 if (coins[i - 1] <= j) dp[i][j] += dp[i][j - coins[i - 1]];
//             }
//         }

//         return (int)dp[n][amount];  // LeetCode expects int
//     }
// };


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0); 
        dp[0] = 1;
        
        for (int c : coins) {
            for (int a = c; a <= amount; a++) {
                dp[a] += dp[a - c];
            }
        }
        
        return dp[amount];        
    }
};
