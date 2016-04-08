class solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if(nums.size() == 0) {return 0;}//empty array no duplicates
		if(nums.size() == 1) {return 1;}//only one element no duplicates
		int i = 1, j = 0;//two pointers
		for(int i = 1; i < nums.size(); ++i) {
			if(nums[i] != nums[i - 1]) {// no duplicates
				nums[++j] = nums[i];
			}
		}
		return j + 1;
	}
};
