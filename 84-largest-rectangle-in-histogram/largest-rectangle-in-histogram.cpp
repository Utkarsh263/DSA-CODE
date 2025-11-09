class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int maxArea =0;

        for(int i=0; i<=n; i++){

            int currHeight = (i==n)? 0: heights[i];

            while(!st.empty() && currHeight < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();

                int rightBoundary =i;
                int leftBoundary = st.empty()? 0: st.top()+1;

                int width = rightBoundary-leftBoundary;
                int area = height*width;
                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        return maxArea;
    }
};