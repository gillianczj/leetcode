class solution {
public:
	void nextPermutation(vector<int>& nums) {
		if(nums.size() < 2) {return;}
		int n = nums.size();
		int j = n - 1;
		while(j >= 0 && nums[j] >= nums[j + 1]) {--j;}//find the first decreasing number
		if(j < 0) {//if the numbers are all increasing, the number is the biggest one, so resort it to be the least one
			sort(nums.begin(), nums.end());
			return;
		}

		int i = j + 1;
		while(i < n && nums[i] > nums[j]) {++i;}
		swap(nums[--i], nums[j]);//find the number just larger than nums[j], then swap
		sort(nums.begin() + j + 1, nums.end());//sort it to be least one
	}
};
