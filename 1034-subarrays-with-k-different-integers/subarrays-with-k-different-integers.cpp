class Solution {
public:
    int atmostK(vector<int> &nums, int k){
        int n = nums.size();
        unordered_map<int, int> freq;
        int left=0;
        int right=0;
        int ans=0;
        for(int right=0; right<n; right++){
            freq[nums[right]]++;

            while(freq.size() > k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }

                left++;
            }

            ans += (right-left+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans= atmostK(nums, k) - atmostK(nums, k-1);
        return ans;
    }
};