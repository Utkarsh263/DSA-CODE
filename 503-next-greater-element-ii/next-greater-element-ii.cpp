class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans (n , -1);

        for(int i= 2*n-1; i>=0; i--){
            int idx = i % n;

            while(!st.empty() && nums[idx] >= st.top()){
                st.pop();
            }

            if(i < n){
                if(!st.empty()){
                    ans[idx] = st.top();
                }
            }

            st.push(nums[idx]);
        }

        return ans;
    }
};