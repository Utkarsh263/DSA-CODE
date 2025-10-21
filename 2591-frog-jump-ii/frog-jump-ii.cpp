class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if(n==0 || n==1){
            return 1;
        }

        int maxJump=0;

        for(int i=2 ;i < n; i++){
            maxJump = max(maxJump , stones[i]-stones[i-2]);
        }

        // Including first and last jump
        maxJump = max(maxJump, stones[1]-stones[0]);
        maxJump = max(maxJump , stones[n-1]-stones[n-2]);

        return maxJump;
    }
};