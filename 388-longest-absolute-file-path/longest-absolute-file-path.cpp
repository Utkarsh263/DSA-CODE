class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int, int> len;
        int maxLen = 0;

        stringstream ss(input);
        string line;

        while (getline(ss, line, '\n')) {
            int depth = 0;

            // Count depth
            while (line[depth] == '\t') {
                depth++;
            }

            // Extract name
            string name = line.substr(depth);
            int currLen = name.length();

            if (depth > 0) {
                currLen += len[depth - 1] + 1; // add '/'
            }

            len[depth] = currLen;

            // If it's a file
            if (name.find('.') != string::npos) {
                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen;
    }
};
