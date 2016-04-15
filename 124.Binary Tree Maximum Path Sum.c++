class solution {
public:
	int maxPathSum(TreeNode* root) {
		int ret = INT_MIN;
		int ps1 = find(root, ret);
		return ret;
	}
private:
	int find(TreeNode* root, int& ret) {
		if(!root) {return 0;}
		int ps1Left = 0, ps1Right = 0;
		if(root->left) {
			ps1Left = max(find(root->left, ret), 0);
		}
		if(root->right) {
			ps1Right = max(find(root->right, ret), 0);
		}
		int ps1 = max(ps1Left, ps1Right) + root->val;
		int ps2 = ps1Left + ps1Right + root->val;
		ret = max(ret, max(ps1, ps2));
		return ps1;
	}
};
