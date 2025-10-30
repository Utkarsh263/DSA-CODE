class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<nums.size(); i++){
            if(i > 0 && nums[i]==nums[i-1]){
                continue;
            }

            int left = i+1;
            int right = n-1;

            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];

                if(sum==0){
                    res.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left]== nums[left+1]){
                    left++;
                    }
                    while(left < right && nums[right]==nums[right-1]){
                    right--;
                    }

                    left++;
                    right--;
                }else if (sum < 0){
                    left++;
                }else{
                    right--;
                }
                
            }
        }
        return res;
    }
};














// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         set<vector<int>>st;
//         for(int i=0; i<n; i++){
//             set<int> hashset;
//             for(int j=i+1; j<n; j++){
//                 int third = -(nums[i]+nums[j]);
//                 if(hashset.find(third) !=hashset.end()){
//                     vector<int> temp = {nums[i], nums[j], third};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(nums[j]);
//             }
//         }

//         vector<vector<int>> ans(st.begin(), st.end());

//         return ans;

//     }
// };