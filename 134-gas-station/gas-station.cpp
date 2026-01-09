class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalFuel = 0;
        int currFuel = 0;
        int start = 0;

        for(int i= 0; i<gas.size(); i++){
            int net = gas[i]- cost[i];

            currFuel += net;
            totalFuel += net;

            if(currFuel < 0){
                currFuel = 0;
                start = i+1;
            }
        }

        return totalFuel >= 0 ? start : -1;
    }
};