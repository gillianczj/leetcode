class solution {
public:
	bool isBalanced(TreeNode* root) {
		//NULl return true
		if(!root) {
			return true;		
		}
		//helper function
		int height = getHeight(root);
		if(height == -1) {
			return false;		
		}
		return true;
	}
private:
	int getHeight(TreeNode* root) {
		if(!root) {
			return 0;		
		}
		int left = getHeight(root->left);
		int right = getHeight(root->right);
		//-1 means unbalanced
		if(left == -1 || right == -1) {
			return -1;
		}	
		if(abs(left - right) > 1) {
			return -1;
		}
		//dont forget +1 to reflect the real height
		return left > right ? left + 1 : right + 1;
	}
}
