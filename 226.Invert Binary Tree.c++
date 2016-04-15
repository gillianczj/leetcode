//recursive
class solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if(!root) {
			return root;
		}

		TreeNode* left = root->left;
		TreeNode* right = root->right;
		root->left = invertTree(right);//invert right child and assign it to the left child
		root->right = invertTree(left);//invert left child and assign it to the right child
		return root;
	}
};

//queue
class solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if(!root) {
			return root;
		}
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()) {//invert children level by level
			TreeNode* node = q.front();
			q.pop();
			TreeNOde* temp = node->left;//swap left and right child
			node->left = node->right;
			node->right = temp;
			if(node->left) {q.push(node->left);}
			if(node->right) {q.push(node->right):}
		}
		return root;
	}
};
