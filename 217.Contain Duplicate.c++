class solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if(nums.size() < 2) {
			return false;
		}
		//hash table
		unordered_map<int, bool> m;
		for(int a : nums) {
			if(m.find(a) == m.end()) {
				m[a] = true;
			}else {
				return true;
			}
		}

		return false;
	}
};
