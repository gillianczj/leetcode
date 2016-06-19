class solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        if(dungeon.empty()) {
            return 0;
        }
        int row = dungeon.size();
        int col = dungeon[0].size();
        int dp[row][col] = {0};//the needed HP
        dp[row - 1][col - 1] = dungeon[row - 1][col - 1] > 0 ? 0 : -dungeon[row - 1][col - 1];//the rightdown cornor
        for(int i = row - 2; i >= 0; --i) {//the rightest column
            dp[i][col - 1] = dungeon[i][col - 1] >= dp[i + 1][col - 1] ? 0 : dp[i + 1][col - 1] - dungeon[i][col - 1];
        }
        for(int j = col - 2; j >= 0; --j) {//the last row
            dp[row - 1][j] = dungeon[row - 1][j] >= dp[row - 1][j + 1] ? 0 : dp[row - 1][j + 1] - dungeon[row - 1][j];
        }
        for(int i = row - 2; i >= 0; --i) {
            for(int j = col - 2; j >= 0; --j) {
                int down = dungeon[i][j] >= dp[i + 1][j] ? 0 : dp[i + 1][j] - dungeon[i][j];
                int right = dungeon[i][j] >= dp[i][j + 1] ? 0 : dp[i][j + 1] - dungeon[i][j];
                dp[i][j] = min(down, right);
            }
        }
        return dp[0][0] + 1;//need one more HP to keep alive
    }
};
