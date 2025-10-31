class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row =0;
        int col = n-1;

        while(row < m && col >=0){
            int element = matrix[row][col];
            if(element == target){
                return true;
            }else if(element > target){
                col--;
            }else{
                row++;
            }
        }

        return false;

    }
};