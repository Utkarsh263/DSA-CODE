class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        long long total =0;
        for(int x :nums){
            total += x;
        }

        long long prefix =0;
        int ans=0;
        int n = nums.size();

        for(int i=0; i< n ; i++){
            long long suffix = total - prefix- nums[i];

            if(nums[i]==0){
                if(prefix==suffix){
                    ans += 2;
                }else if(abs(prefix - suffix)==1){
                    ans += 1;
                }
            }

            prefix += nums[i];
        }

        return ans;
    }
};