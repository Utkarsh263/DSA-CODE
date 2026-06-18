class Solution {
public:
    int trap(vector<int>& height) {
        
        // Using extra space O(n)
        stack<int>st;
        int water = 0;
        int n = height.size();

        for(int i=0; i<n; i++){

            while(!st.empty() && height[st.top()] <= height[i]){

                int bottom = st.top();
                st.pop();

                if(st.empty()){
                    break;
                }

                // Left Boundary 
                int left = st.top();

                int width = i-left-1;

                int heightBounded = min(height[left], height[i]) - height[bottom];

                water += heightBounded*width;
            }

            st.push(i);
        }

        return water;
    }
};