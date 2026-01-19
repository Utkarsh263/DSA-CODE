class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transpose the matrix and reverse the rows 
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m;i++){
            for(int j=i; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row 
        for(int i=0; i<m;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};