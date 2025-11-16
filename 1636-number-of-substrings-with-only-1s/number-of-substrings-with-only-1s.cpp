class Solution {
public:
    int numSub(string s) {
        const int MOD = 1000000007;
        long long ans= 0;
        long long cnt =0;
        for(char ch : s){
            if(ch == '1'){
                cnt++;
                ans = (ans+cnt)%MOD;
            }else{
                cnt =  0;
            }
        }

        return (int)ans;
    }
};