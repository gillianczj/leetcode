class solution {
public:
	int maxProduct(vector<int>& nums) {
		if(nums.empty()) {
			return 0;
		}
		int maxp = nums[0];
		int minp = nums[0];
		int ret = nums[0];
		for(int i = 1; i < nums.size(); ++i) {
			int tmpmax = maxp;
			int tmpmin = minp;
			maxp = max(max(tmpmax * nums[i], tmpmin * nums[i]), nums[i]);//current max
			minp = min(min(tmpmax * nums[i], tmpmin * nums[i]), nums[i]);//current min
			ret = max(ret, maxp);//max so far
		}
		return ret;
	}
};
