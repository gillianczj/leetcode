class solution {
public:
	int maxSubArray(vector<int>& nums) {
		if(nums.empty()) {
			return 0;
		}
		int curSum = nums[0];
		int maxSum = nums[0];
		for(int i = 1; i < nums.size(); ++i) {
			curSum = max(curSum + nums[i], nums[i]);//current max
			maxSum = max(curSum, maxSum);//max so far
		}
		return maxSum;
	}
};
