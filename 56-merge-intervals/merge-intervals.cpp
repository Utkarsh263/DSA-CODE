class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>result;

        if(intervals.empty()){
            return result;
        }

        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            int currstart = intervals[i][0];
            int currend = intervals[i][1];

            //overlapping case
            if(currstart <= end){
                end = max(end , currend);
            }else{
                result.push_back({start, end});
                start = currstart;
                end = currend;
            }
        }

        // push the last interval
        result.push_back({start, end});

        return result;
    }
};