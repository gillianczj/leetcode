class solution {
public:
	int jump(vector<int>& nums) {
		int curMax = 0;
		int njump = 0;
		int i = 0;
		while(curMax < nums.size() - 1) {
			int lastMax = curMax;//last jump the furthest
			while(i <= lastMax) {
				curMax = max(curMax, i + nums[i]);//current jump the furthest
				++i;
			}
			++njump;
		}
		return njump;	
	}	
};
