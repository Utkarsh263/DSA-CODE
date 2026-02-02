class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int x=1;x<nums.size(); x++){
            ans = ans^nums[x];
        }

        return ans;
    }
};