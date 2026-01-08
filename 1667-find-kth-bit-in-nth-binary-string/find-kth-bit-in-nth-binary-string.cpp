class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case
        if (n == 1)
            return '0';

        int length = (1 << n) - 1;      // length of S_n
        int middle = length / 2 + 1;    // middle index (1-based)

        // If k is exactly in the middle
        if (k == middle)
            return '1';

        // If k is in the left half
        if (k < middle)
            return findKthBit(n - 1, k);

        // If k is in the right half (mirror + invert)
        char bit = findKthBit(n - 1, length - k + 1);
        return (bit == '0') ? '1' : '0';
    }
};
