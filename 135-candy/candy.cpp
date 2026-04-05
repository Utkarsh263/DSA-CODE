class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        vector<int>result(n , 1);

        // Left to Right scan 

        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                result[i] = result[i-1] + 1;
            }
        }

        // Left to Right Scan 
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                result[i] = max(result[i] , result[i+1] + 1);
            }
        }

        int total = 0;
        for(int c : result){
            total += c;
        }

        return total;
    }
};