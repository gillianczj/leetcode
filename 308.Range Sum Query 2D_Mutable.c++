class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) {
            return;
        }
        mat.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        bit.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        int diff = val - matrix[row + 1][col + 1];
        for(int i = row + 1; i < mat.size(); i += (i & -i)) {
            for(int j = col + 1; j < mat[0].size(); j += (j & -j)) {
                bit[i][j] += diff;
            }
        }
        mat[row + 1][col + 1] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2 + 1, col2 + 1) - getSum(row1, col2 + 1) - getSum(row2 + 1, col1) + getSum(row1, col1);
    }
private:
    int getSum(int row, int col) {
        int ret = 0;
        for(int i = row; i >= 1; i -= (i & -i)) {
            for(int j = col; j >= 1; j -= (j & -j)) {
                ret += bit[i][j];
            }
        }
        return ret;
    }
private:
    vector<vector<int>> mat;
    vector<vector<int>> bit;
};
