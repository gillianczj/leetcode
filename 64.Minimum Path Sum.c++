class solution {
public:
	int minPathSum(vector<int>& grid) {
		if(grid.empty()) {return 0;}
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<int>> minSum(row, vector<int>(col, 0));//record min sum at every point
		//dynamic programming
		minSum[0][0] = grid[0][0];
		//the first col
		for(int i = 1; i < row; ++i) {
			minSum[i][0] = minSum[i - 1][0] + grid[i][0];
		}
		//the first row
		for(int j = 1; j < col; ++j) {
			minSum[0][j] = minSum[0][j - 1] + grid[0][j];
		}

		for(int i = 1; i < row; ++i) {
			for(int j = 1; j < col; ++j) {
				minSum[i][j] = min(minSum[i - 1][j], minSum[i][j - 1]) + grid[i][j];
			}
		}

		return minSum.back().back();
	}
};
