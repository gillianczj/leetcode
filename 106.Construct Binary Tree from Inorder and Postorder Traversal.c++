class solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if(inorder.size() != postorder.size() || inorder.empty() || postorder.empty()) {return NULL;}
		int n = inorder.size();
		return helper(inorder, postorder, 0, n - 1, 0, n - 1);
	}
private:
	TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int si, int ei, int sp, int ep) {
		if(si > ei || sp > ep) {return NULL;}

		TreeNode* root = new TreeNode(postorder[ep]);//the root
		int rootIndex = -1;
		for(int i = si; i <= ei; ++i) {//find position of root in inorder
			if(inorder[i] == root->val) {
				rootIndex = i;
				break;
			}
		}

		if(rootIndex == -1) {return NULL;}

		int leftTreeSize = rootIndex - si;//left tree size
		int rightTreeSize = ei - rootIndex;//right tree size

		root->left = helper(inorder, postorder, si, rootIndex - 1, sp, sp + leftTreeSize -1);
		root->right = helper(inorder, postorder, rootIndex + 1, ei, ep - rightTreeSize, ep - 1);

		return root;
	}
};
