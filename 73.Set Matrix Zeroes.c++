class solution {
public:
	void setZeroes(vector<int>& matrix) {
		if(matrix.empty()) {return;}
		int row = matrix.size();
		int col = matrix[0].size();
		bool isFirstRow = false;
		bool isFirstCol = false;
		//if the first row would be set to 0
		for(int j = 0; j < col; ++j) {
			if(matrix[0][j] == 0) {
				isFirstRow = true;
				break;
			}
		}
		//if the first col would be set to 0
		for(int i = 0; i < row; ++i) {
			if(matrix[i][0] == 0) {
				isFirstCol = true;
				break;
			}
		}
		//use first col and row to record which rows and cols would be set to 0
		for(int i = 1; i < row; ++i) {
			for(int j = 1; i < col; ++j) {
				if(matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		//set col
		for(int j = 0; j < col; ++j) {
			if(matrix[0][j] == 0) {
				for(int i = 0; i < row; ++i) {
					matrix[i][j] = 0;
				}
			}
		}
		//set row
		for(int i = 0; i < row; ++i) {
			if(matrix[i][0] == 0) {
				for(int j = 0; j < col; ++j) {
					matrix[i][j] = 0;
				}
			}
		}
		//set first col
		if(isFirstCol) {
			for(int i = 0; i < row; ++i) {
				matrix[i][0] = 0;
			}
		}
		//set first row
		if(isFirstRow) {
			for(int j = 0; j < col; ++j) {
				matrix[0][j] = 0;
			}
		}
	}
};
