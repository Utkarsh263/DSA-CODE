class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxVal = INT_MIN;

        for(int num : nums){
            maxVal = max(maxVal, num);
        }

        vector<int>points(maxVal+1, 0);

        for(int n : nums){
            points[n] += n;
        }

        vector<int>dp(maxVal+1 , 0);
        dp[0]=0;
        dp[1]=points[1];

        for(int i=2; i<= maxVal; i++){
            dp[i] = max(dp[i-1], points[i]+dp[i-2]);
        }

        return dp[maxVal];
    }
};