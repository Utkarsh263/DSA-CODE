class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();

        int teams =0;
        for(int j=1; j<n; j++){
            int leftSmaller =0, leftGreater =0;
            int rightSmaller=0, rightGreater =0;
            // count for left half
            for(int i=0; i<j; i++){
                if(rating[i]<rating[j]){
                    leftSmaller++;
                }else if(rating[i]>rating[j]){
                    leftGreater++;
                }
            }
            //count for right half 
            for(int k=j+1; k<n; k++){
                if(rating[k]<rating[j]){
                    rightSmaller++;
                }else if(rating[k] > rating[j]){
                    rightGreater++;
                }
            }

            teams += leftSmaller * rightGreater;
            teams += rightSmaller * leftGreater;
        }

        return teams;
    }
};