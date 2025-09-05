class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n; // use long long to handle INT_MIN safely

        if (nn < 0) nn = -1 * nn; // make exponent positive for calculation

        while (nn > 0) {
            if (nn % 2 == 1) {   // if odd
                ans = ans * x;
                nn = nn - 1;
            } else {             // if even
                x = x * x;
                nn = nn / 2;
            }
        }

        if (n < 0) ans = 1.0 / ans; // handle negative exponent

        return ans;
    }
};
