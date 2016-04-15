class solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if(!p && !q) {//both NULL
			return true;
		}else if(!p || !q) {//one NULl, one is not NULL
			return false;
		}else {//need recursion
			return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
	}
};
