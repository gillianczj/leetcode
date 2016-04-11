class solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ret;
		if(nums.empty()) {return ret;}
		int n = nums.size();
		int i = 0;
		while(i < n) {
			int j = 1;//distance
			while(i + j < n && nums[i + j] - nums[i] == j) {++j;}
			ret.push_back(j == 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));//judge a single number or a range
			i += j;
		}
		return ret;
	}
};
