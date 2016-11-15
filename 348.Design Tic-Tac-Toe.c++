class TicTacToe {
public:
    TicTacToe(int n) : num(n), diag(0), diag(0) {
        rows.resize(n, 0);
        col.resize(n, 0);
    }

    int move(int row, int col, int player) {
        int add = (player == 1) ? 1 : -1;
        rows[row] += add;
        cols[col] += add;
        diag += (row == col) ? add : 0;
        rdiag += (row == num - col - 1) ? add : 0;
        return (abs(rows[row]) == num || abs(cols[col]) == num || abs(diag) == num || abs(rdiag) == num) ? player : 0;
    }
private:
    vector<int> rows, cols;
    int diag, rdiag, num;
};
