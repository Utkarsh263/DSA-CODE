// class Solution {
// public:
//     // Map to store rules:
//     // "AB" -> ['C', 'D']
//     unordered_map<string, vector<char>> rules;

//     // DFS function to check if pyramid can be built from current row
//     bool canBuild(string curr) {
//         // Base case: reached the top
//         if (curr.size() == 1)
//             return true;

//         // Vector to store all possible next rows
//         vector<string> nextRows;
//         buildNextRows(curr, 0, "", nextRows);

//         // Try each possible next row
//         for (string &row : nextRows) {
//             if (canBuild(row))
//                 return true;
//         }

//         return false;
//     }

//     // Function to generate all possible next rows
//     void buildNextRows(string &curr, int idx, string temp,
//                        vector<string> &nextRows) {

//         // Completed one possible next row
//         if (idx == curr.size() - 1) {
//             nextRows.push_back(temp);
//             return;
//         }

//         // Take current adjacent pair
//         string pair = curr.substr(idx, 2);

//         // If no rule exists for this pair, stop (pruning)
//         if (rules.find(pair) == rules.end())
//             return;

//         // Try all possible characters for this pair
//         for (char ch : rules[pair]) {
//             buildNextRows(curr, idx + 1, temp + ch, nextRows);
//         }
//     }

//     bool pyramidTransition(string bottom, vector<string>& allowed) {
//         // Build rules map
//         for (string &s : allowed) {
//             rules[s.substr(0, 2)].push_back(s[2]);
//         }

//         // Start DFS from bottom row
//         return canBuild(bottom);
//     }
// };


class Solution {
public:
    unordered_map<string, vector<char>> rules;
    unordered_map<string, bool> memo;

    bool dfs(string curr) {
        // Base case
        if (curr.size() == 1)
            return true;

        // Memoization check
        if (memo.count(curr))
            return memo[curr];

        vector<string> nextRows;
        buildNext(curr, 0, "", nextRows);

        for (string &row : nextRows) {
            if (dfs(row))
                return memo[curr] = true;
        }

        return memo[curr] = false;
    }

    void buildNext(string &curr, int idx, string temp,
                   vector<string> &nextRows) {

        if (idx == curr.size() - 1) {
            nextRows.push_back(temp);
            return;
        }

        string key = curr.substr(idx, 2);

        // Prune if no rule exists
        if (!rules.count(key))
            return;

        for (char c : rules[key]) {
            buildNext(curr, idx + 1, temp + c, nextRows);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // Build rule map
        for (string &s : allowed) {
            rules[s.substr(0, 2)].push_back(s[2]);
        }

        return dfs(bottom);
    }
};
