class solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size() - 1;
		int maxIndex = 0;
		for(int i = 0; i < maxIndex; ++i) {
			maxIndex = max(maxIndex, i + nums[i]);//update maxIndex
			if(maxIndex >= n) {return true;}
		}
		return false;
	}
};
