class solution {
public:
	int longestConsecutive(TreeNode* root) {
		if(!root) {return 0;}
		return find(root, 0, root->val - 1);
	}
private:
	int find(TreeNode* root, int curLen, int preVal) {
		if(!root) {return curLen;}
		int length = preVal + 1 == root->val ? curLen + 1 : 1;
		return max(length, max(find(root->left, length, root->val), find(root->right, length, root->val)));
	}
};
