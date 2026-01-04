class Solution {
public:
    
    // Function to check prime
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (int n : nums) {

            // ---------- Case 1: p * q ----------
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    int p = i;
                    int q = n / i;

                    // Ensure exactly two distinct primes
                    if (p != q && isPrime(p) && isPrime(q)) {
                        totalSum += (1 + p + q + n);
                    }
                    break;  // stop after first divisor
                }
            }

            // ---------- Case 2: p^3 ----------
            int p = round(cbrt(n));
            if (p * p * p == n && isPrime(p)) {
                totalSum += (1 + p + p * p + n);
            }
        }

        return totalSum;
    }
};
