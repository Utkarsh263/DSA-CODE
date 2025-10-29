class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans =0;

        for(int i=0; i<nums.size();i++ ){
            ans = ans ^ nums[i];
        }

        return ans;
    }
};

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int , int>freq;
//         int ans;

//         for(int i=0; i<nums.size(); i++){
//             freq[nums[i]]++;
//         }

//         for(auto &pair : freq){
//             if(pair.second == 1){
//                 ans = pair.first;
//             }
//         }

//         return ans;
//     }
// };