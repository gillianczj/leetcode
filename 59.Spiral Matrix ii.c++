class solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ret(n, vector<int>(n, 0));
		if(n < 1) {return ret;}
		int num = n / 2;
		int val = 1;
		for(int i = 0; i < num; ++i) {//num times, i is the start
			int end = n - 1 - i;
			for(int j = i; j < end; ++j) {//upper
				ret[i][j] = val++;
			}
			for(int j = i; j < end; ++j) {//right
				ret[j][end] = val++;
			}
			for(int j = end; j > i; --j) {//down
				ret[end][j] = val++;
			}
			for(int j = end; j > i; --j) {//left
				ret[j][i] = val++;
			}
		}
		if(n % 2 == 1) {//odd
			ret[n / 2][n / 2] = val;
		}
		return ret;
	}
};
