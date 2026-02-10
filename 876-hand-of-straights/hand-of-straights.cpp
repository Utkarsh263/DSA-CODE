class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if(hand.size() % groupSize != 0){
            return false;
        }

        map<int, int>freq;
        for(int x: hand){
            freq[x]++;
        }

        for(auto &it : freq){
            int start = it.first;
            int count = it.second;

            if(count > 0){
                for(int i=start; i<start+groupSize; i++){
                    if(freq[i]<count){
                        return false;
                    }

                    freq[i] -= count;
                }
            }
        }
        return true;
    }
};