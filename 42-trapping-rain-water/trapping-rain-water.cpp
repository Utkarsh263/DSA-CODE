class Solution {
public:
    int trap(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int water = 0;

        while(left < right) {

            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            if(leftMax < rightMax) {

                water += leftMax - height[left];
                left++;
            }
            else {

                water += rightMax - height[right];
                right--;
            }
        }

        return water;
    }
};


// class Solution {
// public:
//     int trap(vector<int>& height) {
        
//         stack<int>st;
//         int water = 0;
//         int n = height.size();

//         for(int i=0; i<n; i++){

//             while(!st.empty() && height[st.top()] <= height[i]){

//                 int bottom = st.top();

//                 st.pop();

//                 // No left boundary exist 
//                 if(st.empty()){
//                     break;
//                 }
//                 int left = st.top();
                
//                 int width = i-left-1;

//                 int heightBounded = min(height[left], height[i])-height[bottom];

//                 water += width * heightBounded;
//             }

//             st.push(i);
//         }

//         return water;
//     }
// };