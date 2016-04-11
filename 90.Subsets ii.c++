class solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> allSol;
		vector<int> sol;
		allSol.push_back(sol);//empty subset
		if(nums.empty()) {return allSol;}
		sort(nums.begin(), nums.end());//sort array
		helper(0, nums, sol, allSol);
		return allSol;
	}
private:
	void helper(int start, vector<int>& nums, vector<int>& sol, vector<vector<int>>& allSol) {
		for(int i = start; i < nums.size(); ++i) {//backtracking
			if(i > start && nums[i] == nums[i - 1]) {continue;}//avoid duplicates
			sol.push_back(nums[i]);
			allSol.push_back(sol);
			helper(i + 1, nums, sol, allSol);
			sol.pop_back();
		}
	}
};
