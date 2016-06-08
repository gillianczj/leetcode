class solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty()) {
            return;
        }
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(board[i][j] == 'O' && (i == 0 || i == row - 1 || j == 0 || j == col - 1)) {
                    stack<pair<int, int>> s;
                    s.push(make_pair(i, j));
                    dfs(board, s);
                }
            }
        }
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }else if(board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
private:
    void dfs(vector<vector<char>> &board, stack<pair<int, int>> &s) {
        int row = board.size();
        int col = board[0].size();
        while(!s.empty()) {
            pair<int, int> temp = s.top();
            s.pop();
            board[temp.first][temp.second] = 'Y';
            int dx[4] = {-1, 0, 0, 1};
            int dy[4] = {0, -1, 1, 0};
            for(int i = 0; i < 4; ++i) {
                int x = temp.first + dx[i];
                int y = temp.second + dy[i];
                if(x >= 0 && x < row && y >= 0 && y < col && board[x][y] == 'O') {
                    s.push(make_pair(x, y));
                }
            }
        }
    }
};
