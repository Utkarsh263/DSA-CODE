class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int>nge;
        stack<int>st;

        for(int x : nums2){
            while(!st.empty() && st.top() < x){
                nge[st.top()] = x;
                st.pop();
            }

            st.push(x);
        }

        vector<int>ans;

        for(int x : nums1){
            if(nge.find(x) != nge.end()){
                ans.push_back(nge[x]);
            }else{
                ans.push_back(-1);
            }
        }

        return ans;
    }
};