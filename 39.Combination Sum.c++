class solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> allSol;
		vector<int> sol;
		if(candidates.empty()) {
			return allSol;
		}
		//sort the array
		sort(candidates.begin(), candidates.end());
		helper(candidates, sol, allSol, target, 0);
		return allSol;
	}
private:
	void helper(vector<int>& candidates, vector<int>& sol, vector<int>& allSol, int target, int start) {
		if(target == 0) {
			allSol.push_back(sol);
			return;
		}

		for(int i = start; i < candidates.size(); ++i) {
			if(i > start && candidates[i] == candidates[i -1]) {continue;}//avoid duplicates
			if(candidates[i] <= target) {
				sol.push_back(candidates[i]);
				helper(candidates, sol, allSol, target - candidates[i], i);//one val can appear several times
				sol.pop_back();
			}else {return;}
		}
	}
};
