class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>result;

        sort(intervals.begin(), intervals.end());

        // Always first interval going to add
        result.push_back(intervals[0]);

        for(int i=0; i<intervals.size(); i++){

            // overlap condition 
            if(result.back()[1] >= intervals[i][0]){
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};