class solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        //check row
        for(int i = 0; i < 9; ++i) {
            vector<bool> used(9, false);
            for(int j = 0; j < 9; ++j) {
                if(!isdigit(board[i][j])) {
                    continue;
                }

                int k = board[i][j] - '0';
                if(used[k - 1]) {
                    return false;
                }else {
                    used[k - 1] = true;
                }
            }
        }

        //check col
        for(int j = 0; j < 9; ++j) {
            vector<bool> used(9, false);
            for(int i = 0; i < 9; ++i) {
                if(!isdigit(board[i][j])) {
                    continue;
                }

                int k = board[i][j] - '0';
                if(used[k - 1]) {
                    return false;
                }else {
                    used[k - 1] = true;
                }
            }
        }

        //check subbox
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                vector<bool> used(9, false);
                int row = 3 * i;
                int col = 3 * j;
                for(int m = row; m < row + 3; ++m) {
                    for(int n = col; n < col + 3; ++n) {
                        if(!isdigit(board[m][n])) {
                            continue;
                        }

                        int k = board[m][n] - '0';
                        if(used[k - 1]) {
                            return false;
                        }else {
                            used[k - 1] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};
