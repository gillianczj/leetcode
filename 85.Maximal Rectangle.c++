class solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if(matrix.empty()) {
			return 0;
		}
		int row = matrix.size();
		int col = matrix[0].size();
		vector<vector<int>> ones(row, vector<int>(col, 0));//vector[i][j] records the number of consecutive ones on the row i

		for(int i = 0; i < row; ++i) {//populate the vector
			for(int j = 0; j < col; ++j) {
				if(matrix[i][j] == '1') {
					if(j == 0) {
						ones[i][j] = 1;
					}else {
						ones[i][j] = ones[i][j - 1] + 1;
					}
				}
			}
		}

		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				if(ones[i][j]) {//verify if it could be the bottom right point of a rectangle
					int upper = i - 1;
					int curArea = ones[i][j];
					int width = ones[i][j];
					while(upper >= 0) {
						if(ones[upper][j] == 0) {break;}
						else {
							width = min(width, ones[upper][j];//update the width
							curArea = max(curArea, width * (i - upper + 1));//update the area
							--upper;//go upwards
						}
					}
					maxArea = max(maxArea, curArea);//update the max area
				}
			}
		}
		return maxArea;
	}	
};
