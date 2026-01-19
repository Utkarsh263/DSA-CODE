class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>ps(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                ps[i][j] = mat[i-1][j-1] + ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1];
            }
        }

        int ans=0;

        for(int k=1; k<=min(m, n);k++){
            bool found = false;

            for(int i=k; i<=m; i++){
                for(int j=k; j<=n; j++){

                    int sum = ps[i][j]-ps[i-k][j]-ps[i][j-k]+ps[i-k][j-k];

                    if(sum <= threshold){
                        ans = k;
                        found = true;
                        break;
                    }
                }

                if(found){
                    break;
                }
            }
        }

        return ans;
    }
};