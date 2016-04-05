//O(n)
class solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if(nums.empty()) {return 0;}
		int left = 0, right = 0, sum = 0, minLen = INT_MAX;
		while(right < nums.size()) {
			while(sum < s && right < nums.size()) {
				sum += nums[right++];//the final value of right is the exact value + 1 due to ++
			}
			while(sum >= s && left <= right) {
				minLen = min(minLen, right - left);
				sum -= nums[left++];//the value of left is the exact one
			}
		}

		return minLen == INT_MAX ? 0 : minLen;
	}
};

//O(nlogn)
//binary search
class solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if(nums.empty()) {return 0;}
		int minLen = INT_MAX;
		vector<int> sums(nums.size() + 1, 0);
		//populate the sums vector
		for(int i = 1; i <= nums.size(); ++i) {
			sums[i] = sums[i - 1] + nums[i - 1];
		}

		for(int i = 0; i < nums.size(); ++i) {//start from the ith element in nums
			int right = search(i + 1, nums.size(), sums[i] + s, sums);
			if(right == INT_MAX) {//cant find
				break;
			}
			minLen = min(minLen, right - i);
		}

		return minLen == INT_MAX ? 0 : minLen;
	}
private:
	int search(int left, int right, int target, vector<int>& sums) {
		if(sums[right] < target) {//cant find
			return INT_MAX;
		}

		while(left < right) {//find the one just larger than target
			int mid = left + (right - left) / 2;
			if(sums[mid] >= target) {
				right = mid;
			}else {
				left = mid + 1;
			}
		}
		return left;
	}
};
