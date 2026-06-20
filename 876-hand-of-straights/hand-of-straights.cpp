class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();

        if(n % groupSize){
            return false;
        }

        map<int, int>mp;

        for(int num : hand){
            mp[num]++;
        }

        for(auto &[num, freq] : mp){

            if(freq == 0){
                continue;
            }

            for(int i=1; i<groupSize; i++){

                if(mp[num+i] < freq){
                    return false;
                }

                mp[num+i] -= freq;
            }
        }

        return true;
    }
};