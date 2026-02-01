class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        string word;
        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = NULL;
            word = "";
        }
    };

    vector<string> result;
    int rows, cols;

    void insertWord(TrieNode* root, string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        char ch = board[r][c];
        int idx = ch - 'a';

        if (!node->children[idx]) return;

        node = node->children[idx];

        if (node->word != "") {
            result.push_back(node->word);
            node->word = ""; // avoid duplicates
        }

        board[r][c] = '#'; // mark visited

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto &d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && board[nr][nc] != '#') {
                dfs(board, nr, nc, node);
            }
        }

        board[r][c] = ch; // backtrack
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (string &w : words)
            insertWord(root, w);

        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, root);
            }
        }

        return result;
    }
};
