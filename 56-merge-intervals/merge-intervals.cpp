class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // Sort intervals according to start time 
        sort(intervals.begin(), intervals.end());

        // Result vector 
        vector<vector<int>>result;

        result.push_back(intervals[0]);

        for(auto &interval : intervals){

            // If result is empty or there is no overlap 

            if(interval[0] > result.back()[1]){
                result.push_back(interval);
            }else{
                result.back()[1] = max(result.back()[1] , interval[1]);
            }
        }

        return result;
    }
};