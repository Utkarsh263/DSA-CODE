class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();

        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }

        vector<int> result;
        for(auto &pair : freq){
            if(pair.second > n/3){
                result.push_back(pair.first);
            }
        }

        return result;
    }
};