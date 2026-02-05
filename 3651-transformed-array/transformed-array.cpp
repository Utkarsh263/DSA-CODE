class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {

        int n = nums.size();
        vector<int>ans(n);

        for(int i=0; i<n; i++){
            if(nums[i]==0){
                ans[i] =0;
               
            }

            int index = (i+nums[i])%n;

            if(index < 0){
                index += n;
            }

            ans[i] = nums[index];
        }

        return ans;
    }
};