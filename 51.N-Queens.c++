class solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string> allSol;
		vector<string> sol;
		vector<int> col;
		solve(n, 0, sol, allSol, col);
		return allSol;
	}
private:
	void solve(int n, int irow, vector<string> &sol, vector<vector<string> &allSol, vector<int> &col) {
		if(irow == n) {
			allSol.push_back(sol);
			return;
		}
		//backtracking
		for(int icol = 0; icol < n; ++icol) {
			if(valid(icol, irow, col)) {
				string s(n, '.');
				s[icol] = 'Q';
				sol.push_back(s);
				col.push_back(icol);
				solve(n, irow + 1, sol, allSol, col);
				col.pop_back();
				sol.pop_back();
			}
		}
	}

	bool valid(int icol, int irow, vector<int> &col) {
		if(irow < col.size()) {
			return false;
		}
		//check column and diag
		for(int i = 0; i < col.size(); ++i) {
			if(col[i] == icol || abs(irow - i) == abs(icol - col[i])) {
				return false;
			}
		}

		return true;
	}
};
