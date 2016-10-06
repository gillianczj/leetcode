struct TrieNode {
    string str;
    TrieNode* children[26];
    TrieNode() {
        for(int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
    }
};

struct Trie {
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string s) {
        TrieNode* p = root;
        for(auto c : s) {
            if(!p->children[c - 'a']) {
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
        }
        p->str = s;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        if(board.empty() || words.empty()) {
            return ret;
        }
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        Trie T;
        for(auto word : words) {
            T.insert(word);
        }
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(T.root->children[board[i][j] - 'a']) {
                    search(board, visited, ret, T.root->children[board[i][j] - 'a'], i, j);
                }
            }
        }
        return ret;
    }
private:
    void search(vector<vector<char>>& board, vector<vector<bool>>& visited, vector<string>& ret, TrieNode* p, int x, int y) {
        if(p->str.size()) {
            ret.push_back(p->str);
            p->str.clear();
        }
        visited[x][y] = true;
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};
        for(int i = 0; i < 4; ++i) {
            int m = x + dx[i];
            int n = y + dy[i];
            if(m >= 0 && m < board.size() && n >= 0 && n < board[0].size() && !visited[m][n] && p->children[board[m][n] - 'a']) {
                search(board, visited, ret, p->children[board[m][n] - 'a'], m, n);
            }
        }
        visited[x][y] = false;
    }
};
