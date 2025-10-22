// class Solution {
// public:
//     int n;
//     int solve(int i , int j , vector<vector<int>>&matrix , vector<vector<int>>&dp){
//         if(j <0 || j>=n){
//             return 1e9;
//         }

//         if(i==n-1){
//             return matrix[i][j];
//         }

//         if(dp[i][j]!= -1){
//             return dp[i][j];
//         }

//         int down = matrix[i][j] + solve(i+1 , j, matrix,dp);
//         int left = matrix[i][j] + solve(i + 1, j - 1, matrix, dp);
//         int right = matrix[i][j] + solve(i + 1, j + 1, matrix, dp);

//         return dp[i][j] = min({down , left, right});
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//          n = matrix.size();
//         vector<vector<int>>dp(n , vector<int>(n , -1));
//         int ans= INT_MAX;

//         for(int j=0;j<n; j++){
//             ans = min(ans , solve(0, j, matrix, dp));
//         }
//         return ans;
//     }
// };



class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: last row
        for(int j = 0; j < n; j++) {
            dp[n-1][j] = matrix[n-1][j];
        }

        // Fill DP from bottom-2 row to top
        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                int down = dp[i+1][j];
                int left = (j > 0) ? dp[i+1][j-1] : 1e9;
                int right = (j < n-1) ? dp[i+1][j+1] : 1e9;

                dp[i][j] = matrix[i][j] + min({down, left, right});
            }
        }

        // Minimum in the first row
        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {
            ans = min(ans, dp[0][j]);
        }

        return ans;
    }
};
