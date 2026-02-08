class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int total=0;
        for(int x : cardPoints){
            total += x;
        }

        if(k==n){
            return total;
        }

        int window = n-k;
        int curr =0;
        for(int i=0; i<window; i++){
            curr += cardPoints[i];
        }

        int minSum = curr;
        for(int i=window; i<n; i++){
            curr += cardPoints[i];
            curr -= cardPoints[i-window];
            minSum = min(minSum, curr);
        }

        return total-minSum;
    }
};