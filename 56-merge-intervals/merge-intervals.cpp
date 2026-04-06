class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // Sort intervals according to the start time 
        sort(intervals.begin(), intervals.end());

        vector<vector<int>>result;

        result.push_back(intervals[0]);

        for(auto &interval : intervals){
            // If there is no overlap 

            if(result.back()[1] < interval[0]){
                result.push_back(interval);
            }else{
                result.back()[1] = max(result.back()[1] , interval[1]);
            }
        }

        return result;
    }
};