class solution {
public:
	TreeNode* bulidTree(vector<int>& preorder, vector<int>& inorder) {
		if(preorder.size() != inorder.size() || preorder.empty() || inorder.empty()) {return NULL;}
		int n = inorder.size();
		return helper(preorder, inorder, 0, n - 1, 0, n - 1);
	}
private:
	TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int sp, int ep, int si, int ei) {
		if(si > ei || sp > ep) {return NULL;}

		TreeNode* root = new TreeNode(preorder[sp]);//the root

		int rootIndex = -1;

		for(int i = si; i <= ei; ++i) {//find position of root in inorder
			if(inorder[i] == root->val) {
				rootIndex = i;
				break;
			}
		}

		if(rootIndex == -1) {return NULL;}

		int leftTreeSize = rootIndex - si;
		int rightTreeSize = ei - rootIndex;

		root->left = helper(preorder, inorder, sp + 1, sp + leftTreeSize, si, rootIndex - 1);
		root->right = helper(preorder, inorder, ep - rightTreeSize + 1, ep, rootIndex + 1, ei);

		return root;
	}
};
