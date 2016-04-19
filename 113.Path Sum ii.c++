class solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, sum) {
		vector<vector<int>> allSol;
		vector<int> sol;
		helper(root, sum, sol, allSol);
		return allSol;
	}
private:
	void helper(TreeNode* root, int sum, vector<int>& sol, vector<vector<int>>& allSol) {
		if(!root) {return;}
		sol.push_back(root->val);
		sum -= root->val;
		if(!root->left && !root->right && sum == 0) {//to leaf and get a solution
			allSol.push_back(sol);
			sol.pop_back();//backtracking to uplevel
			return;
		}else {
			helper(root, sum, sol, allSol);
			helper(root, sum, sol, allSol);
			sol.pop_back();//to leaf and do not get a solution, also backtracking to uplevel
		}
	}
};
