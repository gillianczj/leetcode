class solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);//initialization
        if(nums.empty()) {
            return ret;
        }
        int start = 0, end = nums.size() - 1;
        while(start <= end) {//binary search
            int mid = start + (end - start) / 2;
            if(target == nums[mid]) {
                int left = mid, right = mid;
                while(left >= start && nums[left] == nums[mid]) {
                    --left;
                }
                ret[0] = left +1;
                while(right <= end && nums[right] == nums[mid]) {
                    ++right;
                }
                ret[1] = right - 1;
                return ret;
            }else if(target > nums[mid]) {
                start = mid + 1;
            }else {
                end = mid - 1;
            }
        }
        return ret;
    }
};
