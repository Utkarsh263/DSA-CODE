class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n , 1);

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};




















































































// class Solution {
// public:
//     int solveusingrecursion(vector<int>&nums,int curr,int prev){
//         //base case
//         if(curr>= nums.size()){
//             return 0;
//         }

//         int include=0;
//         if(prev==-1 || nums[curr]>nums[prev]){
//             include= 1+ solveusingrecursion(nums,curr+1,curr);
//         }
//         int exclude= 0+ solveusingrecursion(nums,curr+1,prev);
//         int ans= max(include,exclude);
//         return ans;
//     }
//     int solveusingmem(vector<int>&nums,int curr,int prev, vector<vector<int>>&dp){
//         //base case
//         if(curr>=nums.size()){
//             return 0;
//         }

//         if(dp[curr][prev+1] !=-1){
//             return dp[curr][prev+1];
//         }
//         //include and exclude case
//         int include =0;
//         if(prev==-1 || nums[prev]<nums[curr]){
//             include=1+ solveusingmem(nums,curr+1,curr,dp);

//         }
//         int exclude = 0+ solveusingmem(nums,curr+1,prev,dp);
//         dp[curr][prev+1]= max(include, exclude);

//         return dp[curr][prev+1];


//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int curr=0;
//         int prev=-1;
//         int n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         int ans= solveusingmem(nums,curr,prev,dp);
//         return ans;
//     }
// };