class solution {
public:
	void flatten(TreeNode* root) {
		if(!root) {return;}
		while(root) {
			if(root->left) {//if there is a left sub tree
				TreeNode* pre = root->left;
				while(pre->right) {pre = pre->right;}//find the most right node of left sub tree
				pre->right = root->right;//let right sub tree of root be right sub tree of pre
				root->right = root->left;//move whole left sub tree to right
				root->left = NULL;//left sub tree becomes null
			}
			root = root->right;//move downside
		}
	}
};
