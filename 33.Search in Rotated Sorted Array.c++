class solution {
pubilc:
	int search(vector<int>& nums, int target) {
		if(nums.empty()) {return -1;}
		int start = 0, end = nums.size() - 1;
		while(start <= end) {
			int mid = start + (end - start) / 2;
			if(target == nums[mid]) {return mid;}
			if(nums[mid] < nums[end]) {//right half is sorted
				if(target > nums[mid] && target <= nums[end]) {//which part target belongs to
					start = mid + 1;
				}else {
					end = mid - 1;
				}
			}else {//left half is sorted
				if(target >= nums[start] && target < nums[mid]) {
					end = mid - 1;
				}else {
					start = mid + 1;
				}
			}
		}
		return -1;
	}
};
