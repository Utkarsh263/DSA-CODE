class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + floor((numBottles-1)/(numExchange-1));
    }
};