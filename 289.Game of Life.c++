class solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if(board.empty() || board[0].empty()) {
			return;
		}
		int row = board.size();
		int col = board[0].size();
		int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
		int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				int count = 0;
				for(int k = 0; k < 8; ++k) {
					int x = i + dx[k];
					int y = j + dy[k];
					if(x >= 0 && x < row && y >= 0 && y < col && (board[x][y] == 2 || board[x][y] == 3)) {++count;}
				}

				if(board[i][j] && (count < 2 || count > 3)) {
					board[i][j] = 2;
				}else if (!board[i][j] && count == 3) {
					board[i][j] = 3;
				}
			}
		}

		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				board[i][j] %= 2;
			}
		}
	}
};
//four states
//state 0 : 0->0
//state 1 : 1->1
//state 2 : 1->0
//state 3 : 0->1
