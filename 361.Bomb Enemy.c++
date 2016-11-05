class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty()) {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();
        int ret = 0;
        int rowCnt = 0;
        vector<int> colCnt(col, 0);
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(j == 0 || grid[i][j - 1] == 'W') {
                    rowCnt = 0;
                    for(int k = j; k < col && grid[i][k] != 'W'; ++k) {
                        rowCnt += grid[i][j] == 'E';
                    }
                }
                if(i == 0 || grid[i - 1][j] == 'W') {
                    colCnt[j] = 0;
                    for(int k = i; k < row && grid[k][j] != 'W'; ++k) {
                        colCnt[j] += grid[i][j] == 'E';
                    }
                }
                if(grid[i][j] == '0') {
                    ret = max(ret, rowCnt + colCnt[j]);
                }
            }
        }
        return ret;
    }
};
