class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);

        for(int i=0; i<n; i++){
            if(nums[i]==0){
                ans[i] =0;
                continue;
            }

            int new_index = (i+nums[i])%n;

            if(new_index < 0){
                new_index += n;
            }

            ans[i] = nums[new_index];

        }

        return ans;
    }
};