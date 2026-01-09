class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalNet = 0;
        int currFuel = 0;
        int start = 0;

        for(int i=0; i<gas.size(); i++){
            int net = gas[i] - cost[i];

            totalNet += net;
            currFuel += net;

            if(currFuel < 0){
                start = i+1;
                currFuel =0;
            }
        }

        return totalNet >= 0 ? start : -1;
    }
};