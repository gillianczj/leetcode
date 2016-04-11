class solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int row = board.size();
		int col = board[0].size();
		if(board.empty() || row * col < word.size()) {return false;}
		vector<vector<bool>> used(row, vector<bool>(col, false));//record each item is used or not
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				if(find(i, j, board, used, word, 0) {return true;}
			}
		}
		return false;
	}
private:
	bool find(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& used, string& word, int idx) {//dfs
		if(idx == word.size()) {return true;}
		if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || used[row][col] || board[row][col] != word[idx]) {return false;}
		used[row][col] = true;
		if(find(row - 1, col, board, used, word, idx + 1)) {return true;}
		if(find(row + 1, col, board, used, word, idx + 1)) {return true;}
		if(find(row, col - 1, board, used, word, idx + 1)) {return true;}
		if(find(row, col + 1, board, used, word, idx + 1)) {return true;}
		used[row][col] = false;
		return false;
	}
};
