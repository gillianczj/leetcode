//recursive
class solution {
public:
	bool isSymmetric(TreeNode* root) {
		if(!root) {return true;}
		return helper(root->left, root->right);
	}
private:
	bool helper(TreeNode* lc, TreeNode* rc) {
		if(!lc && !rc) {return true;}
		else if(!lc || !rc) {return false;}
		else {return (lc->val == rc->val) && helper(lc->left, rc->right) && helper(lc->right, rc->left);}
	}
};
//queue
class solution {
public:
	bool isSymmetric(TreeNode* root) {
		if(!root) {return true;}
		queue<TreeNode*> ql, qr;//left subtree and right subtree
		ql.push(root->left);
		qr.push(root->right);
		while(!ql.empty() && !qr.empty()) {
			TreeNode* lnode = ql.front():
			TreeNode* rnode = qr.front();
			ql.pop();
			qr.pop();
			if(!lnode && !rnode) {continue;}//two null pointers
			else if(!lnode || !rnode) {return false;}//one is null, the other is not
			else if(lnode->val != rnode->val) {return false;}//two values do not match
			else {
				ql.push(lnode->left);//left subtree from left to right
				ql.push(lnode->right);
				qr.push(rnode->right);//right subtree from right to left
				qr.push(rnode->left);
			}
		}
		if(!ql.empty() || !qr.empty()) {return false;}
		return true;
	}
};
