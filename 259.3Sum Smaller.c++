class solution {
public:
	int threeSumSmaller(vector<int>& nums, int target) {
		if(nums.size() < 3) {
			return 0;
		}
		int count = 0;
		//sort
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size() - 2; ++i) {
			int left = i + 1;
			int right = nums.size() - 1;
			while(left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				if(sum >= target) {
					--right;
				}else {
					count += right - left;//all combinations between satisfy 
					++left;
				}
			}
		}
		return count;
	}
};
