class solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ret;
		if(!root) {
			return ret;
		}
		DFS(root, to_string(root->val), ret);
		return ret;
	}
private:
	void DFS(TreeNode* root, string s, vector<string>& ret) {
		if(!root->left && !root->right) {//get to leaf ,then push the string to the array
			ret.push_back(s);
		}
		if(root->left) {
			DFS(root->left, s + "->" + to_string(root->left->val), ret);
		}
		if(root->right) {
			DFS(root->right, s + "->" + to_string(root->right->val), ret);
		}
	}
};
