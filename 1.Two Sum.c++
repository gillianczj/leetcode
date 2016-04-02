class solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		if(nums.size() < 2) {
			return ret;
		}

		//hash table
		unordered_map<int, int> mp;//first value, second index
		int n = nums.size();

		for(int i = 0; i < n; ++i) {
			mp[nums[i]] = i;
		}

		for(int i = 0; i < n; ++i) {
			int rest = target - nums[i];
			if(mp.count(rest)) {
				int idx = mp[rest];
				if(idx == i) {continue;}//cant be the same one
				else if(idx < i) {
					ret.push_back(idx);
					ret.push_back(i);
					break;//only one solution, no need to do more calculation
				}else {
					ret.push_back(i);
					ret.push_back(idx);
					break;
				}
			}
		}

		return ret;
 	}
};
