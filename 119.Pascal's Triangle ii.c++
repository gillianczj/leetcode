class solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ret;
		if(rowIndex < 0) {return ret;}
		ret.push_back(1);//for rowIndex == 0
		if(rowIndex == 0) {return ret;}
		ret.push_back(1);//for rowIndex == 1
		if(rowIndex == 1) {return ret;}

		for(int i = 2; i <= rowIndex; ++i) {
			for(int j = i - 1; j >= 1; --j) {//from back to front
				ret[j] = ret[j] + ret[j - 1];
			}
			ret.push_back(1);//the end 1
		}
		return ret;
	}
};
