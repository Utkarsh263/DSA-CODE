class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        // Check divisibility
        if(hand.size() % groupSize != 0){
            return false;
        }

        // Frequency map 
        unordered_map<int, int>freq;
        for(int h : hand){
            freq[h]++;
        }

        // Min Heap 
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int h : hand){
            pq.push(h);
        }

        while(!pq.empty()){
            int start = pq.top();
            pq.pop();

            // Skip if its already used 
            if(freq[start]==0){
                continue;
            }

            for(int i=0; i<groupSize; i++){
                int curr = start + i;

                if(freq[curr]==0){
                    return false;
                }

                freq[curr]--;
            }
        }

        return true;
    }
};