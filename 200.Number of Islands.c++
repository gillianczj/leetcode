class solution {
public:
    int numIsland(vector<vector<char>> &grid) {
        if(grid.empty()) {
            return 0;
        }
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    search(i, j, visited, grid);
                    ++count;
                }
            }
        }
        return count;
    }
private:
    void search(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &grid) {
        visited[i][j] =true;
        if(i + 1 < grid.size() && !visited[i + 1][j] && grid[i + 1][j] == '1') {
            search(i + 1, j, visited, grid);
        }
        if(j + 1 < grid[0].size() && !visited[i][j + 1] && grid[i][j + 1] == '1') {
            search(i, j + 1, visited, grid);
        }
        if(i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == '1') {
            search(i - 1, j, visited, grid);
        }
        if(j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == '1') {
            search(i, j - 1, visited, grid);
        }
    }
};
