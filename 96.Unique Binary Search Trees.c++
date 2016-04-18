class solution {
public:
	int numTrees(int n) {
		if(n < 1) {
			return 0;
		}
		vector<int> ret(n + 1, 0);
		ret[0] = 1;
		//dynamic programming
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < i; ++j) {//left * right
				ret[i] += ret[j] * ret[i - 1 - j];
			}
		}
		return ret.back();
	}
};
