class solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
		if(matrix.empty()) {return ret;}
		int row = matrix.size();
		int col = matrix[0].size();
		int num = (min(row, col) + 1) / 2;//num times
		for(int i = 0; i < num; ++i) {//i is the start
			int lastRow = row - 1 - i;
			int lastCol = col - 1 - i;
			if(i == lastRow) {//only one row left
				for(int j = i; j <= lastCol; ++j) {
					ret.push_back(matrix[i][j];
				}
			}else if(i == lastCol) {//only one col left
				for(int j = i; j <= lastRow; ++j) {
					ret.push_back(matrix[j][i];
				}
			}else {//go over a cycle
				for(int j = i; j < lastCol; ++j) {//upper
					ret.push_back(matrix[i][j]);
				}
				for(int j = i; j < lastRow; ++j) {//right
					ret.push_back(matrix[j][lastCol];
				}
				for(int j = lastCol; j > i; --j) {//down
					ret.push_back(matrix[lastRow][j];
				}
				for(int j = lastRow; j > i; --j) {
					ret.push_back(matrix[j][i]);//left
				}
			}
		}
		return ret;
	}
};
