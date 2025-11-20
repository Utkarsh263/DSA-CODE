class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        // Sort intervals by:
        // 1. end ascending
        // 2. start descending (for same end)
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if (a[1] == b[1]) 
                return a[0] > b[0];
            return a[1] < b[1];
        });

        int ans = 0;
        
        // last two selected points
        int secondLast = -1;
        int last = -1;

        for (auto &in : intervals) {
            int a = in[0], b = in[1];

            // Case 1: Interval already has two points (do nothing)
            if (a <= secondLast) {
                continue;
            }
            // Case 2: Interval has only one of our points
            else if (a <= last) {
                ans += 1;
                secondLast = last;
                last = b;
            }
            // Case 3: Interval has zero of our points
            else {
                ans += 2;
                secondLast = b - 1;
                last = b;
            }
        }

        return ans;
    }
};
