class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // Sort the array 
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;
        for(int i=1; i<arr.size(); i++){
            minDiff = min(minDiff , abs(arr[i]-arr[i-1]));
        }

        // Formulating the result 
        vector<vector<int>>result;
        for(int i=1; i<arr.size(); i++){
            if(abs(arr[i]-arr[i-1]) == minDiff){
                result.push_back({arr[i-1], arr[i]});
            }
        }

        return result;
    }
};