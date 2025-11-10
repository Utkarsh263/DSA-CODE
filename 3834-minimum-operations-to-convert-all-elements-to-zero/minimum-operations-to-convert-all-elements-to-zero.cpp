class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        stack<int> st;
        st.push(0); // senitel value zero

        for(int num : nums){
            // Pop all values strictly greater than current num
            while(!st.empty() && st.top() > num){
                st.pop();
            }
            // If stack now empty OR the top value < current num  
            // => we need a new operation

            if(st.empty() || st.top()< num){
                ans++;
                st.push(num);
            }

            // If st.top() == num, we do nothing (we can reuse an existing operation)

        }

        return ans;
    }
};