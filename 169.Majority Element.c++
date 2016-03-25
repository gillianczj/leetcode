class solution {
public:
	int majorityElement(vector<int> &nums) {
		int m = 0, cm = 0;
		//moore voting algorithm
		for(int a : nums) {
			if(m == a) {
				++cm;
			}else if(cm == 0) {
				m = a;
				cm = 1;
			}else {
				--cm;
			}
		}

		return m;
	}
};
