class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) {
            return 0;
        }
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int ret = 1;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                ret = max(ret, dfs(matrix, dp, i, j));
            }
        }
        return ret;
    }
private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if(dp[i][j]) {
            return dp[i][j];
        }
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int maxLen = 1;
        for(int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x < 0 || y < 0 || x >= row || y >= col || matrix[x][y] <= matrix[i][j]) {
                continue;
            }
            int len = 1 + dfs(matrix, dp, x, y);
            maxLen = max(len, maxLen);
        }
        dp[i][j] = maxLen;
        return dp[i][j];
    }
};
