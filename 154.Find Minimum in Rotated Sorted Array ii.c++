class solution {
public:
	int findMin(vector<int>& nums) {
		if(nums.size() == 1) {
			return nums[0];
		}

		int start = 0, end = nums.size() - 1;
		//the minimum is in the unsorted half
		while(start < end) {
			int mid = start + (end - start) / 2;
			if(nums[mid] < nums[end]) {//right half is sorted
				end = mid;
			}else if(nums[mid] > nums[end]) {//left half is sorted
				start = mid + 1;
			}else {//duplicates occur
				--end;//remove one duplicate
			}
		}

		return nums[start];
	}
};
