class Solution {
public:
    int smallestNumber(int n) {
        long long ans =1;
        while(ans < n){
            ans = (ans << 1) | 1;
        }


        return ans;
    }
};