class solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> allSol;
		vector<int> sol;
		vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		if(k < 1 || k > 9) {return allSol;}
		helper(sol, allSol, nums, k, n, 0);
		return allSol;
	}
private:
	void helper(vector<int>& sol, vector<vector<int>>& allSol, vector<int>& nums, int k, int target, int start) {
		if(target == 0 && sol.size() == k) {//base case
			allSol.push_back(sol);
			return;
		}

		for(int i = start; i < 9; ++i) {
			if(nums[i] <= target && sol.size() < k) {//backtracking
				sol.push_back(nums[i]);
				helper(sol, allSol, nums, k, target - nums[i], i + 1);//recursively
				sol.pop_back();
			}else {return;}
		}
	}
};
