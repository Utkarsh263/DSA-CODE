class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;  // will act like a stack

        for (char c : num) {
            // while we can remove and stack top is bigger than current digit
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // if still k digits need to be removed, remove from end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // remove leading zeros
        int i = 0;
        while (i < (int)st.size() && st[i] == '0') i++;

        string result = st.substr(i);

        return result.empty() ? "0" : result;
    }
};
