class solution {
public:
	int findPeakElement(Vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while(left < right) {
			int mid = left + (right - left) / 2;
			if(nums[mid] < nums[mid + 1]) {//there must be at least solution on the higher side
				left = mid + 1;
			}else {
				right = mid;
			}
		}

		return left;
	}
};
