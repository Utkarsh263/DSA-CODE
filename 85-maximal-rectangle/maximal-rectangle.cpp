class Solution {
public:
    int largestAreaRectangle(vector<int> heights){
        stack<int> st;
        int n = heights.size();
        int maxArea=0;

        for(int i=0; i<=n; i++){
            int currHeight = (i==n)? 0: heights[i];

            while(!st.empty() && currHeight < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();

                int rightBoundary =i;
                int leftBoundary = st.empty() ? 0: st.top()+1;

                int width = rightBoundary - leftBoundary;
                int area = height*width;
                maxArea = max(maxArea , area);
            }
            st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()){
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols ,0);
        int maxArea =0;

        for(int r=0; r< rows; r++){
            for(int c=0; c< cols; c++){
                if(matrix[r][c] == '1'){
                    heights[c] += 1;
                }else{
                    heights[c]=0;
                }
            }

            maxArea = max(maxArea , largestAreaRectangle(heights));
        }

        return maxArea;
    }
};