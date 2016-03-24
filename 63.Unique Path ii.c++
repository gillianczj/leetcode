class solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
		int row = obstacleGrid.size();
		int col = obstacleGrid[0].size();
		vector<vector<int>> path(row, vector<int>(col, 0));
		int i, j;
		//first column
		for(i = 0; i < row; ++i) {
			if(obstacleGrid[i][0] == 0) {
				path[i][0] = 1;
			}else {
				break;
			}
		}

		while(i < row) {
			path[i++][0] = 0;
		}

		//first row
		for(j = 0; j < col; ++j) {
			if(obstacleGrid[0][j] == 0) {
				path[0][j] = 1;
			}else {
				break;
			}
		}

		while(j < col) {
			path[0][j++] = 0;
		}

		//DP
		for(i = 1; i < row; ++i) {
			for(j = 1; j < col; ++j) {
				if(obstacleGrid[i][j] == 1) {
					path[i][j] = 0;
				}else {
					path[i][j] = path[i-1][j] + path[i][j-1];
				}
			}
		}

		return path[row-1][col-1];
	}
};
