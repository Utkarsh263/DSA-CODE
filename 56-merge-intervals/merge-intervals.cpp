class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort the array on the basis of start interval

        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for(int i=1; i<n; i++){
            auto &last = result.back();

            if(intervals[i][0] <= last[1]){
                // case of merging the interval
                last[1] = max(last[1], intervals[i][1]);
            }else{
                // case of non merging the intervals
                result.push_back(intervals[i]);
            }
        }


        return result;
    }
};