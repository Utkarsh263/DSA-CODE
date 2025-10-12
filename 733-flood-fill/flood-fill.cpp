class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c,int oldColor, int newColor){
        int rows = image.size();
        int cols = image[0].size();

        if(r<0 || c<0 || r>=rows ||c>=cols){
            return;
        }
        if(image[r][c] != oldColor){
            return;
        }

        image[r][c]= newColor;

        dfs(image , r+1 , c , oldColor , newColor);
        dfs(image , r-1 , c , oldColor , newColor);
        dfs(image , r , c-1 , oldColor , newColor);
        dfs(image , r , c+1 , oldColor , newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor == newColor ){
            return image;
        }
        dfs(image , sr , sc , oldColor , newColor);
        return image;
    }
};