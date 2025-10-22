// class Solution {
// public:
//     int solve(int i , int j , vector<vector<int>>&triangle, vector<vector<int>>&dp , int n){
//         if(i==n-1){
//             return triangle[i][j];
//         }

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         int down = triangle[i][j] + solve(i+1, j, triangle, dp, n);
//         int diag = triangle[i][j] + solve(i+1, j+1 , triangle , dp, n);

//         return dp[i][j]= min(down , diag);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>>dp(n , vector<int>(n, -1));

//         return solve(0, 0, triangle, dp, n);
//     }
// };



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j < triangle[i].size(); j++)
                triangle[i][j] +=
                    min(triangle[i + 1][j], triangle[i + 1][j + 1]);

        return triangle[0][0];
    }
};
