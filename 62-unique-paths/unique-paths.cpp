class Solution {
public:
    int countPaths(int i, int j , vector<vector<int>>&dp){
        if(i==0 || j==0){
            return 1;
        }

        if(i <0 || j <0){
            return 0;  // path doesn't exist 
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up = countPaths(i-1, j, dp);
        int down = countPaths(i , j-1, dp);

        return dp[i][j] = up+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m , vector<int>(n, -1));
        return countPaths(m-1 , n-1, dp);
    }
};