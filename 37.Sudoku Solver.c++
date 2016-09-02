class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board);
    } 
private:
    bool solveSudokuHelper(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') {
                    for(int k = 1; k <= 9; ++k) {
                        board[i][j] = '0' + k;
                        if(isValid(board, i, j) && solveSudokuHelper(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col) {
        for(int i = 0; i < 9; ++i) {
            if(i != row && board[i][col] == board[row][col]) {
                return false;
            }
        }
        for(int j = 0; j < 9; ++j) {
            if(j != col && board[row][j] == board[row][col]) {
                return false;
            }
        }
        int r = row / 3 * 3;
        int c = col / 3 * 3;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(r + i != row && c + j != col && board[r + i][c + j] == board[row][col]) {
                    return false;
                }
            }
        }
        return true;
    }
};
