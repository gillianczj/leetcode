class solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if(nums.size() < 3) {
			return INT_MAX;
		}
		//sort the vector
		sort(nums.begin(), nums.end());
		int minDiff = INT_MAX;

		for(int i = 0; i < nums.size() - 2; ++i) {//three numbers make nums.size()-2
			int left = i + 1;
			int right = nums.size() - 1;
			while(left < right) {
				int diff = nums[i] + nums[left] + nums[right] - target;
				if(abs(diff) < abs(minDiff)) {
					minDiff = diff;
				}

				if(diff == 0) {
					return target;
				}else if(diff > 0) {
					--right;
				}else {
					++left;
				}
			}
		}

		return target + minDiff;
	}
};
