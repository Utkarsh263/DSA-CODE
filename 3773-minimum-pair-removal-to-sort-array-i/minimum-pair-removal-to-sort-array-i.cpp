class Solution {
public:
    int minPair(vector<int> &arr){
        int minSum = INT_MAX;
        int pos = -1;

        for(int i=0; i<arr.size()-1; i++){
            if(arr[i] + arr[i+1] < minSum){
                minSum = arr[i]+arr[i+1];
                pos = i;
            }
        }

        return pos;
    }

    void mergePair(vector<int>&arr , int pos){
        arr[pos] += arr[pos+1];
        arr.erase(arr.begin()+pos+1);
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while(!is_sorted(nums.begin(), nums.end())){
            mergePair(nums, minPair(nums));
            ops += 1;
        }

        return ops;
    }
};