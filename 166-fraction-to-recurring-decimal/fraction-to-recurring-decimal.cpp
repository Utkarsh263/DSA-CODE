class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }

        // Convert to long to avoid overflow
        long num = labs(numerator);
        long den = labs(denominator);

        // Integer part
        result += to_string(num / den);
        long remainder = num % den;

        if (remainder == 0) return result; // No decimal part

        result += ".";
        unordered_map<long, int> remainderIndex;

        while (remainder != 0) {
            if (remainderIndex.count(remainder)) {
                result.insert(remainderIndex[remainder], "(");
                result += ")";
                break;
            }

            remainderIndex[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }

        return result;
    }
};
