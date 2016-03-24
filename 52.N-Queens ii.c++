class solution {
public:
	int totalNQueens(int n) {
		int num;
		vector<int> col;
		solve(n, 0, col, num);
		return num;
	}
private:
	void solve(int n, int irow, vector<int> &col, int &num) {
		if(irow == n) {
			++num;
			return;
		}
		//backtracking
		for(int icol = 0; icol < n; ++icol) {
			if(valid(icol, irow, col)) {
				col.push_back(icol);
				solve(n, irow + 1, col, num);
				col.pop_back();
			}
		}
	}

	bool valid(int icol, int irow, vector<int> &col) {
		if(irow < col.size()) {
			return false;
		}
		//check column and diag
		for(int i = 0; i < col.size(); ++i) {
			if(col[i] == icol || abs(irow - i) == abs(icol - col[i]) {
				return false;
			}
		}

		return true;
	}
};
