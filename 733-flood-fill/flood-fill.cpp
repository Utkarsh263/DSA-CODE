class Solution {
public:
    void dfs(vector<vector<int>>&image , int r, int c, int original , int newColor){
        
        int rows = image.size();
        int cols = image[0].size();

        // Boundary Check 
        if(r<0 || c<0 || r>=rows || c>=cols || image[r][c] != original){
            return;
        }

        image[r][c] = newColor;

        // Explore further 4 directions
        dfs(image, r+1 , c, original , newColor);
        dfs(image , r-1 , c, original, newColor);
        dfs(image , r, c+1, original , newColor);
        dfs(image , r, c-1 , original , newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int original = image[sr][sc];

        if(original == newColor){
            return image;
        }

        dfs(image , sr, sc , original , newColor);
        return image;
    }
};