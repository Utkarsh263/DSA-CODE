class Solution {
public:
    int MOD = 1e9 + 7;

    long long power(long long x , long long n){

        long long ans = 1;

        while(n > 0){

            if(n % 2 == 1){
                ans = (ans * x)%MOD;
            }

            x = (x*x)%MOD;
            n /= 2;
        }

        return ans;
    }
    int countGoodNumbers(long long n) {
        
        long long evenPos = (n+1)/2;
        long long oddPos = n/2;

        long long evenWays = power(5, evenPos);
        long long oddWays = power(4, oddPos);

        return (evenWays * oddWays) % MOD;
    }
};