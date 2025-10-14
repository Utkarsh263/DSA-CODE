class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prevRun = 0;
        int currRun=1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                currRun++;
            }else{
                if(currRun /2 >=k || min(prevRun , currRun) >=k){
                    return true;
                }
                prevRun = currRun;
                currRun =1;
            }
        }

        if (currRun / 2 >= k || min(prevRun, currRun) >= k) {
            return true;
        }

        return false;
    }
};