class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int total = 0;

        for(int x : cardPoints){
            total += x;
        }

        int windowSize = n-k;

        // Finding window sum 
        int sum = 0;
        for(int i=0; i<windowSize; i++){
            sum += cardPoints[i];
        }

        int minSum = sum;

        for(int i= windowSize ; i<n; i++){

            sum = sum + cardPoints[i] - cardPoints[i-windowSize];
            minSum = min(sum , minSum);
        }

        return total-minSum;
    }
};