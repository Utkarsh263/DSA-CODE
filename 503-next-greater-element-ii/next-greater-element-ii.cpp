class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        st.push(0);
        int n = nums.size();
        vector<int> res(n, -1);
        for(int i = 1; i < n; i++){
            //Replace all the lower values
            while(!st.empty() && nums[i] > nums[st.top()]){
                res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[i] > nums[st.top()]){
                res[st.top()] = nums[i];
                st.pop();
            }
            //If empty or the indice we checking is already the forth which we checked, exit
            if(st.empty() || st.top() < i) break;  
        }
        return res;
    }
};