class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum =0;
        int negativeCount =0;
        int minAbs = INT_MAX;

        for(auto &row : matrix){
            for(int val : row){
                if(val < 0){
                    negativeCount++;
                }

                sum = sum + abs(val);
                minAbs = min(minAbs , abs(val));
            }
        }

        if(negativeCount %2 !=0){
            sum = sum - 2*minAbs;
        }

        return sum;
    }
};