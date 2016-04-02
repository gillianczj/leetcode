class solution {
public:
	int findDuplicate(vector<int>& nums) {
		int low = 1, high = nums.size() - 1;
		while(low < high) {//binary search
			int mid = low + (high - low) / 2;
			int count = 0;
			for(int a : nums) {
				if(a <= mid) {++count;}
			}

			if(count <= mid) {//if # of numbers smaller than x <= x, then duplicates are in the other part
				low = mid + 1;
			}else {
				high = mid;
			}
		}
		return low;
	}
};
