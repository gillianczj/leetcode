class solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if(matrix.empty()) {
            return 0;
        }
        int ret = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> state(row, vector<int>(col, 0));
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(matrix[i][j] == '1') {
                    state[i][j] = 1;
                    ret = 1;
                }
            }
        }
        for(int i = 1; i < row; ++i) {
            for(int j = 1; j < col; ++j) {
                if(state[i][j]) {
                    state[i][j] = min(state[i - 1][j], min(state[i][j - 1], state[i - 1][j - 1])) + 1;
                    ret = max(ret, state[i][j]);
                }
            }
        }
        return ret * ret;
    }
};
