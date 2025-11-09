class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>nextGreater;
        stack<int> st;

        for(int i= nums2.size()-1;i>=0; i--){
            int curr = nums2[i];

            while(!st.empty() && st.top() <= curr){
                st.pop();
            }

            if(!st.empty()){
                nextGreater[curr] = st.top();
            }else{
                nextGreater[curr] = -1;
            }

            st.push(curr);
        }

        vector<int> result;
        for(int num : nums1){
            result.push_back(nextGreater[num]);
        }

        return result;
    }
};