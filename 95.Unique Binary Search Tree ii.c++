class solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> sol;
		if(n < 1) {return sol;}
		sol = helper(1, n);
		return sol;
	}
private:
	vector<TreeNode*> helper(int min, int max) {
		vector<TreeNode*> ret;
		if(min > max) {
			ret.push_back(NULL);
			return ret;
		}

		for(int i = min; i <= max; ++i) {//recursive
			vector<TreeNode*> leftSubTree = helper(min, i - 1);
			vector<TreeNode*> rightSubTree = helper(i + 1, max);
			for(int j = 0; j < leftSubTree.size(); ++j) {
				for(int k = 0; k < rightSubTree.size(); ++k) {
					TreeNode* root = new TreeNode(i);
					root->left = leftSubTree[j];
					root->right = rightSubTree[k];
					ret.push_back(root);
				}
			}
		}
		return ret;
	}
};
