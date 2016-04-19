class solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ret;
		if(!root) {return ret;}
		queue<TreeNode*> q;//level by level
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			TreeNode* temp = q.front();
			q.pop();
			if(temp->left) {//push left
				q.push(temp->left);
			}
			if(temp->right) {//push right
				q.push(temp->right);
			}
			if(!q.front()) {//the last one
				ret.push_back(temp->val);
				q.pop():
				if(!q.empty()) {//not the last level
					q.push(NULL);
				}
			}
		}
		return ret;
	}
};
