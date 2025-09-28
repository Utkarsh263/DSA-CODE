class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        
        // Step 1: If not divisible, return false
        if (n % groupSize != 0) return false;

        // Step 2: Count frequency of cards
        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        // Step 3: Greedy - start from smallest card
        for (auto& it : count) {
            int card = it.first;
            int freq = it.second;

            if (freq > 0) {
                // Try to form group starting at 'card'
                for (int i = 0; i < groupSize; i++) {
                    if (count[card + i] < freq) {
                        return false; // not enough cards
                    }
                    count[card + i] -= freq; // use cards
                }
            }
        }

        return true;
    }
};
