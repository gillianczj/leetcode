class solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if(nums.empty()) {return 0;}
		int maxLen = 1;
		unordered_set<int> s;
		for(int a : nums) {
			s.insert(a);
		}

		for(int i = 0; i < nums.size(); ++i) {
			if(s.empty()) {break;}
			int curLen = 0;
			int curNum = nums[i];
			while(s.count(curNum)) {//go forward
				s.erase(curNum);//avoid recalculating
				++curLen;
				++curNum;
			}
			curNum = nums[i] - 1;
			while(s.count(curNum)) {//go backward
				s.erase(curNum);
				++curLen;
				--curNum;
			}

			maxLen = max(curLen, maxLen);
		}

		return maxLen;
	}
};
