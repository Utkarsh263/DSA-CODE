class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string currStr = "";
        int currNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                currNum = currNum * 10 + (c - '0');
            }
            else if (c == '[') {
                st.push({currStr, currNum});
                currStr = "";
                currNum = 0;
            }
            else if (c == ']') {
                auto [prevStr, repeat] = st.top();
                st.pop();

                string temp = "";
                for (int i = 0; i < repeat; i++)
                    temp += currStr;

                currStr = prevStr + temp;
            }
            else {
                currStr += c;
            }
        }
        return currStr;
    }
};
