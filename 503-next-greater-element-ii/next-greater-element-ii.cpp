class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        // Here we will traverse the array twice and start filling answers during teh second pass 

        int n = nums.size();
        stack<int>st;
        vector<int>ans(n);

        for(int i=2*n-1; i>=0; i--){

            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }

            // Fill the answers in second pass 
            if(i<n){
                if(st.empty()){
                    ans[i] = -1;
                }else{
                    ans[i] = st.top();
                }
            }

            st.push(nums[i%n]);
        }

        return ans;
    }
};