class solution {
public:
	vector<int> majorityElement(vector<int> &nums) {
		vector<int> ret;
		int m = 0, n = 0, cm = 0, cn = 0;
		//moore voting algorithm
		for(int a : nums) {
			//check equality first
			if(m == a) {
				++cm;
			}else if(n == a) {
				++cn;
			}else if(cm == 0) {
				m = a;
				cm = 1;
			}else if(cn == 0) {
				n = a;
				cn = 1;
			}else {
				--cm;
				--cn;
			}
		}
		//reset count
		cm = 0;
		cn = 0;

		for(int a : nums) {
			if(m == a) {
				++cm;
			}else if(n == a) {
				++cn;
			}
		}

		//check satisfy or not
		if(cm > floor(nums.size() / 3)) {
			ret.push_back(m);
		}
		if(cn > floor(nums.size() / 3)) {
			ret.push_back(n);
		}

		return ret;
	}
};
