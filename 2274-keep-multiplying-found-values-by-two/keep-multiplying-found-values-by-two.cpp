class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set s(nums.begin(), nums.end());
        while(s.count(original)){
            original *= 2;
        }

        return original;
    }
};