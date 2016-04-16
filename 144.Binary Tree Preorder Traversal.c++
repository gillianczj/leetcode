//recursive
class solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		preorder(root, ret);
		return ret;
	}
private:
	void preorder(TreeNode* root, vector<int>& ret) {
		if(!root) {
			return;
		}
		ret.push_back(root->val);
		preorder(root->left, ret);
		preorder(root->right, ret);
	}
};
