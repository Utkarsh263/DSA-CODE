class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0){
            return 0;
        }

        unordered_map<int, int>mp;
        for(int x : nums){
            mp[x]++;
        }
        int ans=0;
        for(auto &p : mp){
            if(k==0){
                if(p.second>1){
                    ans++;
                }
            }else{
                if(mp.count(p.first+k)){
                    ans++;
                }
            }
        }

        return ans;
    }
};