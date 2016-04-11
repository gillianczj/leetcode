class solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if(triangle.empty()) {return 0};
		for(int i = 1; i < triangle.size(); ++i) {
			for(int j = 0; j <= i; ++j) {//dynamic programming
				if(j == 0) {//the first one
					triangle[i][j] += triangle[i - 1][j];
				}else if(j == i) {//the last one
					triangle[i][j] += triangle[i - 1][j - 1];
				}else {
					triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
				}
			}
		}
		sort(triangle.back().begin(), triangle.back().end());//sort
		return triangle.back()[0];//the minimum one
	}
};
