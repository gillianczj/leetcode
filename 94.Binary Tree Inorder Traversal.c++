//non recursive
class solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> s;
		while(root) {//push all the way to the leftest node
			s.push(root);
			root = root->left;
		}
		while(!s.empty()) {
			TreeNode* temp = s.top();//top is the smallest one
			s.pop();
			ret.push_back(temp->val);
			if(temp->right) {//if the popped node has a right child, repeat the pushing all the way to the leftest node step
				temp = temp->right;
				while(temp) {
					s.push(temp);
					temp = temp->left;
				}
			}
		}
		return ret;
	}
}

//recursive
class solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		inorder(root, ret);
		return ret;
	}
private:
	bool inorder(TreeNode* root, vector<int>& ret) {
		if(!root) {
			return;
		}
		inorder(root->left, ret);
		ret.push_back(root->val);
		inorder(root->right, ret);
	}
};
