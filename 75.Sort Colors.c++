class solution {
public:
	void sortColors(vector<int>& nums) {
		int left = o; right = nums.size() - 1, i = 0;//left side of 'left'are all 0s; right side of 'right' are all 2s
		while(i <= right) {
			if(nums[i] == 0) {
				swap(nums[i++], nums[left++]);//since  between i and left are all 1s, so after swap i can move forward without considering the new number swapped here
			}else if(nums[i] == 1) {
				++i;
			}else {
				swap(nums[i], nums[right--]);//do not know the new number, so i has to stay
			}
		} 
	}
};
