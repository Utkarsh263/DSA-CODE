class Solution {
public:
    int nextBeautifulNumber(int n) {
        while (!isBalanced(++n))
            ;
        return n;
    }

private:
    bool isBalanced(int num) {
        vector<int> count(10, 0);
        while (num > 0) {
            int d = num % 10;
            if (d == 0) return false;    // a 0 digit invalidates it
            count[d]++;
            num /= 10;
        }
        for (int d = 1; d < 10; d++) {
            if (count[d] > 0 && count[d] != d)
                return false;
        }
        return true;
    }
};
