class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		while(root) {//push all the way to the leftest node
			s.push(root);
			root = root->left;
		}
	}
	
	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();//if the stack is not empty, there exists a next smallest node
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* node = s.top();
		s.pop();
		int ret = node->val;
		if(node->right) {//check if the poped node has a right child
			node = node->right;
			while(node) {//push all the way to the leftest node
				s.push(node);
				node = node->left;
			}
		}
		return ret;
	}

private:
	stack<TreeNode*> s;
};
