class solution {
public:
	bool search(vector<int>& nums, int target) {
		if(nums.empty()) {return false;}
		int start = 0, end = nums.size() - 1;
		while(start <= end) {
			int mid = start + (end - start) / 2;
			if(target == nums[mid]) {return true;}
			if(nums[mid] < nums[end]) {//right half is sorted
				if(target > nums[mid] && target <= nums[end]) {//judge which part target belongs to 
					start = mid + 1;
				}else {
					end = mid - 1;
				}
			}else if(nums[mid] > nums[end]) {//right half is not sorted
				if(target >= nums[start] && target < nums[mid]) {//judge which part target belongs to
					end = mid - 1;
				}else {
					start = mid + 1;
				}
			}else {//duplicates
				--end;
			}
		}
		return false;
	}
};
