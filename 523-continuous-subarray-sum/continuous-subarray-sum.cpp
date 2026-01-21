class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        mp[0] = -1;

        int prefixSum =0;

        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];

            int remainder;
            if(k != 0){
                remainder = prefixSum % k;
            }else{
                remainder = prefixSum;
            }

            if(mp.find(remainder) != mp.end()){
                if(i - mp[remainder] >=2){
                    return true;
                }
            }else{
                mp[remainder] =i;
            }
        }

        return false;
    }
};