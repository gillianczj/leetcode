//hash table, use O(n) space
class solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if(nums.empty()) {return 1;}
		//hash table
		unordered_map<int, bool> mp;
		for(int a : nums) {
			if(mp.count(a)) {
				continue;
			}else {
				mp[a] = true;
			}
		}
		int i = 1;
		while(1) {
			if(mp.count(i)) {
				++i;
			}else {
				return i;
			}
		}
	}
};

//use constant space
class solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if(nums.empty()) {return 1;}

		int n = nums.size();//worst case is 1-n are in the array
		int i = 0;
		//put numbers to where they should be
		while(i < n) {
			if(nums[i] > 0 && nums[i] <= n && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
				swap(nums[i], nums[nums[i] - 1]);
			}else {
				++i;
			}
		}

		for(i = 0; i < n; ++i) {
			if(nums[i] != i + 1) {
				return i + 1;
			}
		}

		return n + 1;//worst case
	}
};
