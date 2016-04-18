class solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if(!root) {return false;}
		sum -= root->val;
		if(!root->left && !root->right) {//get to the leaf
			return sum == 0 ? true : false;
		}else {
			return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
		}
	}
};
