class Solution {
public:
    long long subMax(vector<int>&nums){

        int n = nums.size();
        stack<long long>st;
        vector<long long>left(n), right(n);

        // Previous Greater element 
        for(int i=0; i<n; i++){

            while(!st.empty() && nums[st.top()] < nums[i]){
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
        for(int i=n-1; i>=0; i--){

            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }

            if(st.empty()){
                right[i] = n-i;
            }else{
                right[i] = st.top() - i;
            }

            st.push(i);
        }

        long long ans = 0;

        for(int i=0; i<n; i++){
            long long contri = 1LL * nums[i] * left[i]* right[i];
            ans += contri;
        }

        return ans;
    }

    long long subMin(vector<int>&nums){

        int n = nums.size();
        vector<long long>left(n), right(n);
        stack<long long>st;

        // Prev Smaller element 
        for(int i=0; i<n; i++){

            while(!st.empty() && nums[st.top()] > nums[i]){
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

        // Next Smaller Element 
        for(int i=n-1; i>=0; i--){

            while(!st.empty() && nums[st.top()] >= nums[i]){
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

            long long contri = 1LL * nums[i] * left[i] * right[i];

            ans += contri;
        }

        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        
        // We will have to find Sum of Sub array minimums and maximim seperately 

        return subMax(nums) - subMin(nums);
    }
};