class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeros;
        
        // Step 1: Count trailing zeros for each row
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            trailingZeros.push_back(count);
        }
        
        int swaps = 0;
        
        // Step 2: Greedy placement
        for (int i = 0; i < n; i++) {
            int required = n - i - 1;
            int j = i;
            
            // Find first row that satisfies requirement
            while (j < n && trailingZeros[j] < required) {
                j++;
            }
            
            // If no such row exists
            if (j == n)
                return -1;
            
            // Bring row j up to position i using adjacent swaps
            while (j > i) {
                swap(trailingZeros[j], trailingZeros[j - 1]);
                swaps++;
                j--;
            }
        }
        
        return swaps;
    }
};