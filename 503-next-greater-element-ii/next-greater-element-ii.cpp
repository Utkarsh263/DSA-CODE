class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        // Here we will traverse the array twice but we will fill the answwr during the second pass from n-1 to 0
        int n = nums.size();
        vector<int>ans(n);
        stack<int>st;

        for(int i= 2*n-1; i>=0; i--){

            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }

            // Filling up answers 
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