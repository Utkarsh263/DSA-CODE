class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long base , long long exp){
        long long result = 1;
        base = base % MOD;

        while(exp >0){
            if(exp %2 == 1){
                result = (result * base)%MOD;
                exp--;
            }else{
                base = (base* base) % MOD;
                exp = exp/2;
            }
        }

        return result;
    }
    int countGoodNumbers(long long n) {
        long long evencount = (n+1)/2;
        long long oddcount = n/2;

        long long part1 = modPow(5, evencount);
        long long part2 = modPow(4, oddcount);

        return (part1*part2)%MOD;
    
    }
};