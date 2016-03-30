class solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		if(nums.size() < 3) {
			return ret;
		}
		//sort the array
		sort(nums.begin(), nums.end());

		if(int i = 0; i < nums.size() - 2; ++i) {
			int left = i + 1;
			int right = nums.size() - 1;
			while(left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				vector<int> cur;
				while(i < nums.size() && nums[i] == nums[i + 1]) {
					++i;
				}
				if(sum == 0) {
					cur.push_back(nums[i]);
					cur.push_back(nums[left]);
					cur.push_back(nums[right]);
					ret.push_back(cur);
					++left;//move left
					--right;//move right
					while(left < right && nums[left] == nums[left - 1]) {//duplicates
						++left;
					}
					while(left < right && nums[right] == nums[right + 1]) {//duplicates
						--right;			
					}
				}else if(sum > 0) {
					--right;
					while(left < right && nums[right] == nums[right + 1]) {//duplicates
						--right;			
					}
				}else {
					++left;
					while(left < right && nums[left] == nums[left - 1]) {//duplicates
						++left;
					}
				}
			}
		}
		return ret;
	}
};
