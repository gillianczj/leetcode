class solution {
public:
	int findMin(vector<int>& nums) {
		if(nums.size() == 1) {
			return nums[0];
		}

		int left = 0, right = nums.size() - 1;

		while(left < right) {
			int mid = left + (right - left) / 2;
			if(nums[mid] < nums[right]) {//right half is sorted
				right = mid;
			}else {//left half is sorted
				left = mid + 1;
			}
		}

		return nums[left];
	}
};
