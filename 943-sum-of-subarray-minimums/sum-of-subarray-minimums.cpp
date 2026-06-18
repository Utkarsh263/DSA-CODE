class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        vector<int>left(n), right(n);
        const int MOD = 1e9 + 7;
        stack<int>st;

        // Prev Smaller Element 
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            if(st.empty()){
                left[i] = i+1;
            }else{
                left[i] = i-st.top();
            }

            st.push(i);
        }

        // Empty the stack 
        while(!st.empty()){
            st.pop();
        }

        // Next Greater Element 

        for(int i = n-1; i>=0; i--){

            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(st.empty()){
                right[i] = n-i;
            }else{
                right[i] = st.top()-i;
            }

            st.push(i);
        }

        long long ans = 0;

        for(int i=0; i<n; i++){

            long long contribution = 1LL * arr[i]* left[i]*right[i];

            ans = (ans+contribution) % MOD;
        }

        return ans;
        
    }
};