class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        int n = nums.size();

        if(n % k != 0){
            return false;
        }

        map<int, int>mp;

        for(int num : nums){
            mp[num]++;
        }

        for(auto &[num, freq] : mp){

            if(freq == 0){
                continue;
            }

            for(int i=1; i<k; i++){

                if(mp[num+i] < freq){
                    return false;
                }

                mp[num+i] -= freq;
            }
        }

        return true;
    }
};