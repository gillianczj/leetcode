class solution {
public:
	int countNodes(TreeNode* root) {
		if(!root) {return 0;}
		
		int left = getHeight(root, true);//true means left
		int right = getHeight(root, false);//false means right

		if(left == right) {//complete
			return (1 << left) - 1;
		}else {//not complete divide and conquer
			return countNodes(root->left) + countNodes(root->right) + 1;
		}
	}
private:
	int getHeight(TreeNode* root, bool flag) {
		int h = 0;
		if(flag) {
			while(root) {
				root = root->left;
				++h;
			}
		}else {
			while(root) {
				root = root->right;
				++h;
			}
		}
		return h;
	}
};
