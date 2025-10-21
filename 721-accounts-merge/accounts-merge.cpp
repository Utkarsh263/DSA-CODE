#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(string email, unordered_map<string, vector<string>>& graph, unordered_set<string>& visited, vector<string>& emails) {
        visited.insert(email);
        emails.push_back(email);
        for (auto &neighbor : graph[email]) {
            if (!visited.count(neighbor)) {
                dfs(neighbor, graph, visited, emails);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> graph; // email -> connected emails
        unordered_map<string, string> emailToName;    // email -> name

        // Build the graph
        for (auto &account : accounts) {
            string name = account[0];
            string firstEmail = account[1];
            emailToName[firstEmail] = name;
            for (int i = 1; i < account.size(); i++) {
                string email = account[i];
                emailToName[email] = name;
                // Connect this email with the first email of the account
                graph[firstEmail].push_back(email);
                graph[email].push_back(firstEmail);
            }
        }

        unordered_set<string> visited;
        vector<vector<string>> result;

        // DFS for each email
        for (auto &[email, _] : graph) {
            if (!visited.count(email)) {
                vector<string> emails;
                dfs(email, graph, visited, emails);
                sort(emails.begin(), emails.end());
                emails.insert(emails.begin(), emailToName[email]); // add name at front
                result.push_back(emails);
            }
        }

        return result;
    }
};
