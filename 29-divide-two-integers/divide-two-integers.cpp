class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }

        bool negative = (dividend< 0) ^ (divisor<0);

        long long a = llabs(dividend);
        long long b = llabs(divisor);

        long long ans =0;

        while(a >= b){
            long long temp =b;
            long long multiple = 1;

            while((temp << 1) <= a){
                temp <<= 1;
                multiple <<=1;
            }

            a -= temp;
            ans += multiple;
        }

        return negative ? -ans : ans;
    }
};