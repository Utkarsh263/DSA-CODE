class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int>leftMin(n) , rightMin(n) , leftMax(n) , rightMax(n);

        stack<int>st;

        for(int i=0; i<n; i++){  // Prev Smaller
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            leftMin[i] = st.empty()? i+1 : i-st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1; i>=0; i--){ // Next Smaller
            while(!st.empty() && nums[st.top()]>= nums[i]){
                st.pop();
            }
            rightMin[i] = st.empty() ? n-i : st.top()-i;
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=0; i<n; i++){ // Previous Greater
            while(!st.empty() && nums[st.top()]< nums[i]){
                st.pop();
                
            }
            leftMax[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1; i>= 0; i--){
            while(!st.empty() && nums[st.top()]<= nums[i]){
                st.pop();
            }
            rightMax[i] = st.empty() ? n-i : st.top()-i;
            st.push(i);
        }

        long long result = 0;
        for(int i=0; i<n ; i++){
            long long maxContribution = (long long)nums[i] * leftMax[i] * rightMax[i];
            long long minContribution = (long long)nums[i] * leftMin[i] * rightMin[i];
            result += (maxContribution - minContribution);
        }

        return result;
    }
};