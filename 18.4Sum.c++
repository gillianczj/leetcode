class solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> allSol;
		vector<int> sol;
		sort(nums.begin(), nums.end());
		kSum(nums, 0, nums.size() - 1, target, 4, sol, allSol);
		return allSol;
	}
private:
	void kSum(vector<int>& nums, int start, int end, int target, int k, vector<int>& sol, vector<vector<int>>& allSol) {
		if(k <= 0) {
			return;
		}else if(k == 1) {
			for(int i = start; i <= end; ++i) {
				if(i > start && nums[i] == nums[i - 1]) {continue;}//avoid duplicates
				if(nums[i] == target) {
					sol.push_back(nums[i]);
					allSol.push_back(sol);
					sol.pop_back();
				}
			}
		}else if(k == 2) {
			while(start < end) {
				int sum = nums[start] + nums[end];
				if(sum == target) {
					sol.push_back(nums[start]);
					sol.push_back(nums[end]);
					allSol.push_back(sol);
					sol.pop_back();
					sol.pop_back();
					++start;
					--end;
					while(start < end && nums[start] == nums[start - 1]) {++start;}//avoid duplicates
					while(start < end && nums[end] == nums[end + 1]) {--end;}//avoid duplicates
				}else if(sum > target) {
					--end;
				}else {
					++start;
				}
			}
		}else {
			for(int i = start; i <= end - k + 1; ++i) {
				if(i > start && nums[i] == nums[i - 1]) {continue;}//avoid duplicates
				sol.push_back(nums[i]);
				kSum(nums, i + 1, end, target - nums[i], k - 1, sol, allSol);
				sol.pop_back();
			}
		}
	}
};
