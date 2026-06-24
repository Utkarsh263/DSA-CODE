class Solution {
public:
    int m;
    int n;
    void dfs(vector<vector<int>>&image , int i, int j , int newColor, int orgColor){

        if(i<0 || j<0 || i>=m || j>= n || image[i][j] != orgColor || image[i][j] == newColor){
            return;
        }
        image[i][j] = newColor;

        dfs(image , i+1, j, newColor , orgColor);
        dfs(image , i-1, j, newColor , orgColor);
        dfs(image , i, j+1, newColor , orgColor);
        dfs(image , i, j-1, newColor , orgColor);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        m = image.size();
        n = image[0].size();

        int orgColor = image[sr][sc];

        dfs(image, sr, sc, color, orgColor);

        return image;
    }
};