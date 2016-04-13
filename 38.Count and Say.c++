class solution {
public:
	string countAndSay(int n) {
		if(n < 1) {
			return "";
		}
		string ret = "1";
		for(int i = 2; i <= n; ++i) {
			int count = 1;
			char pre = ret[0];
			string temp = "";
			for(int j = 1; j < ret.size(); ++j) {
				if(ret[j] == pre) {
					++count;//number of pre
				}else {
					temp += to_string(count);
					temp.push_back(pre);
					count = 1;//reset
					pre = ret[j];
				}
			}
			temp += to_string(count);
			temp.push_back(pre);
			ret = temp;
		}
		return ret;
	}
};
