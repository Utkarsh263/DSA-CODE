class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transpose the matrix 
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }

        // Reverse the rows 
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Brute Force approach 
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> temp(n, vector<int>(n));

//         // Place elements in rotated positions
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 temp[j][n - 1 - i] = matrix[i][j];
//             }
//         }

//         // Copy back to original matrix
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 matrix[i][j] = temp[i][j];
//             }
//         }
//     }
// };
