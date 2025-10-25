class Solution {
public:
    int totalMoney(int n) {
        int total = 0, monday = 1;
        int day = 0;

        while (day < n) {
            for (int i = 0; i < 7 && day < n; i++) {
                total += monday + i;
                day++;
            }
            monday++;
        }
        return total;
    }
};
