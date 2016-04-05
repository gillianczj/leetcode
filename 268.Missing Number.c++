class solution {
public:
	int missingNumber(vector<int>& nums) {
		//use XOR
		int ret = 0;
		for(int i = 0; i < nums.size(); ++i) {
			ret ^= nums[i] ^ (i + 1);
		}
		return ret;
	}
};

//hash
class solution {
public:
	int missingNumber(vector<int>& nums) {
		unordered_set<int> s;
		for(int a : nums) {
			s.insert(a);
		}

		for(int i = 0; i <= nums.size(); ++i) {
			if(!s.count(i)) {
				return i;
			}
		}
	}
};
