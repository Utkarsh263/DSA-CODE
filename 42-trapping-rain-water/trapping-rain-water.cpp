class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water=0;
        stack<int> st;

        for(int i=0; i<n ; i++){
            while(!st.empty() && height[i] > height[st.top()]){
                int bottom = st.top();
                st.pop();

                if(st.empty()){
                    break;
                }

                int left = st.top();
                int width = i-left-1;
                int boundedHeight = min(height[i], height[left])-height[bottom];

                water+= width*boundedHeight;
            }
            st.push(i);
        }
        return water;
    }
};