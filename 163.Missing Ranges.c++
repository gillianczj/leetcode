class solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> ret;
		int index = 0;
		int cur = lower;
		if(nums.empty()) {
			ret.push_back(to_string(lower) + "->" + to_string(upper));
			return ret;
		}

		while(cur <= upper && index < nums.size()) {
			if(cur == nums[index]) {
				++cur;
				++index;
			}else {
				if(cur + 1 == nums[index]) {//miss one number
					ret.push_back(to_string(cur));
					++cur;
				}else {//missing more than one
					ret.push_back(to_string(cur) + "->" + to_string(nums[index] - 1));
					cur = nums[index];
				}
			}
		}

		if(cur <= upper) {//range beyond the vector
			ret.push_back(to_string(cur) + (cur < upper ? "->" + to_string(upper) : ""); 
		}
		return ret;
	}	
};
