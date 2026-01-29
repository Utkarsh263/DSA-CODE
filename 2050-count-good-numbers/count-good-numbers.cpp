class Solution {
public:
    static const long long MOD = 1000000007;

    long long power(long long base, long long exp){
        if(exp ==0){
            return 1;
        }

        long long half = power(base, exp/2);

        if(exp %2 ==0){
            return (half*half)%MOD;
        }else{
            return (base*half*half)%MOD;
        }
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;  // 0,2,4,6,8 and even indices will always be n+1/2
        long long odd = n/2; // prime number are 2,3,5,7 and odd indices will always be n/2

        long long evenWays = power(5, even);
        long long oddWays = power(4, odd);

        return (evenWays * oddWays)%MOD;
    }
};