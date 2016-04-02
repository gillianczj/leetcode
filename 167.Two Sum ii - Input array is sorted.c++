class solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> ret;
		if(numbers.size() < 2) {return ret;}

		int left = 0;
		int right = numbers.size() - 1;
		while(left < right) {
			int sum = numbers[left] + numbers[right];
			if(sum == target) {
				ret.push_back(left + 1);//not zero-based
				ret.push_back(right + 1);
				return ret;//only one solution
			}else if(sum > target) {
				--right;
			}else {
				++left;
			}
		}
	}
};
