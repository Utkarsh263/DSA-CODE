class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int high = arr.size();

        while(low < high){
            int mid = (low + high)/2;
            int missing = arr[mid]-(mid+1);

            if(missing < k){
                low = mid+1; // move right to larger value of k
            }else{
                high = mid;
            }
        }

        return low+k;
    }
};