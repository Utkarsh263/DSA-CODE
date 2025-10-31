class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        vector<int> result;
        for(auto &pair : m){
            if(pair.second==2){
                result.push_back(pair.first);
            }
        }
        return result;
    }
};