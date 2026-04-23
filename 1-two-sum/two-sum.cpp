class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        int n = nums.size();

        for(int i=0; i<n; i++){
            int rest = target - nums[i];

            if(mp.find(rest) != mp.end()){
                return {i, mp[rest]};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};