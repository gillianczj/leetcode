class solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> allSol;
		vector<int> sol;
		if(candidates.empty()) {
			return allSol;
		}
		sort(candidates.begin(), candidates.end());//sort the array
		helper(candidates, sol, allSol, target, 0);
		return allSol;
	}
private:
	void helper(vector<int>& candidates, vector<int>& sol, vector<vector<int>>& allSol, int target, int start) {
		if(target == 0) {
			allSol.push_back(sol);
			return;
		}

		for(int i = start; i < candidates.size(); ++i) {
			if(i > start && candidates[i] == candidates[i - 1]) {continue;}//avoid duplicates
			if(candidates[i] < target) {//backtracking
				sol.push_back(candidates[i]);
				helper(candidates, sol, allSol, target - candidates[i], i + 1);
				sol.pop_back();
			}else {//since sorted, if the present one is too large, then the following ones are also too large, no need to calculate
				return;
			}
		}
	}
};
