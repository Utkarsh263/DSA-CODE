class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>map;
        stack<int>st;

        for(int num : nums2){

            while(!st.empty() && st.top()< num){
                map[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Giving -1 to  those elements who has no greater
        while(!st.empty()){
            map[st.top()] = -1;
            st.pop();
        }

        vector<int>result;
        for(int num : nums1){
            result.push_back(map[num]);
        }

        return result;
    }
};