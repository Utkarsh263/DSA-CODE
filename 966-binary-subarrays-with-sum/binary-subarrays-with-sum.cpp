class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int>count; // (PrefixSum -> Frequency)

        count[0]=1; // Empty Subarray

        int prefixSum=0;
        int result=0;

        for(int num : nums){
            prefixSum += num;

            if(count.find(prefixSum - goal) != count.end()){
                result += count[prefixSum - goal];
            }

            count[prefixSum]++;
        }
        return result;
    }
};