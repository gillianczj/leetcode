class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(!matrix.empty()) {
            int row = matrix.size();
            int col = matrix[0].size();
            sum.resize(row + 1);
            for(int i = 0; i <= row; ++i) {
                sum[i].resize(col + 1);
                sum[i][0] = 0;
            }
            sum[0] = {0};
            for(int i = 0; i < row; ++i) {
                for(int j = 0; j < col; ++j) {
                   sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 + 1][col2 + 1] - sum[row2 + 1][col1] - sum[row1][col + 1] + sum[row1][row1];
    }
private:
    vector<vector<int>> sum;
};
