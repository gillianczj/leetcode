//recursive
class solution {
public:
	int maxDepth(TreeNode* root) {
		if(!root) {
			return 0;
		}
		int lmax = maxDepth(root->left);
		int rmax = maxDepth(root->right);
		return max(lmax, rmax) + 1;
	}
};

//queue
class solution {
	int maxDepth(TreeNode* root) {
		if(!root) {
			return 0;
		}

		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL);//NULL marks the end of a level
		int count = 0;
		while(!q.empty()) {
			TreeNode* temp = q.front();
			q.pop();
			if(temp) {//not the end
				if(temp->left) {p.push(temp->left;}
				if(temp->right) {p.push(temp->right;}
			}else {//end
				++count;//increase the count
				if(!q.empty()) {//check if it is the leaf
					q.push(NULL);//not, then push one more NULL to mark the end of the level
				}
			}
		}
		return count;
	}
};
