class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);

        for(int i=0; i<n; i++){
            if(nums[i]==0){
                ans[i] =nums[i];

            }

            int index = (nums[i] +i)%n;
            if(index < 0){
                index += n;
            }

            ans[i] = nums[index];
        }
        return ans;
    }
};