class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;   // "122" → only one '1'

        vector<int> s(n);
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;

        int read = 2;   // pointer to read counts
        int write = 3;  // pointer to write numbers
        int num = 1;    // next number to write (1 or 2)
        int countOne = 1;

        while (write < n) {
            int times = s[read];  // how many times to write

            for (int i = 0; i < times && write < n; i++) {
                s[write] = num;
                if (num == 1) countOne++;
                write++;
            }

            num = (num == 1) ? 2 : 1; // alternate
            read++;
        }

        return countOne;
    }
};
