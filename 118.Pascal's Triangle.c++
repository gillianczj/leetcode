class solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		vector<int> temp;
		if(numRows == 0) {return ret;}
		temp.push_back(1);
		ret.push_back(temp);
		if(numRows == 1) {return ret;}
		
		for(int i = 1; i < numRows; ++i) {
			temp.clear();
			temp.push_back(1);//the beginning 1
			for(int j = 1; j < i; ++j) {//the between
				temp.push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
			}
			temp.push_back(1);//the end 1
			ret.push_back(temp);
		}
		return ret;
	}
};
